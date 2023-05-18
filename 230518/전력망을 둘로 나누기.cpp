#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
#include <stack>
#include <math.h>

using namespace std;

vector<bool> visit;

int dfs(int start, vector<vector<int>>& g)
{
	int size = g.size();

	vector<bool> visited(size, false);

	visit[start] = true;

	stack<int> s;

	s.push(start);

	int cnt = 0;

	while (!s.empty())
	{
		int cur = s.top();

		cout << cur << " ";

		s.pop();

		for (int i = 0; i < size; i++)
		{
			if (g[cur][i] == 1 && !visited[i])
			{
				s.push(i);

				cnt++;

				visited[i] = true;
			}
		}
	}

	return cnt;
}

int solution(int n, vector<vector<int>> wires) {
	int answer = INT_MAX;

	vector<vector<int>> g(102, vector<int>(102, 0));

	for (int i = 0; i < wires.size(); i++)
	{
		int x = wires[i][0];
		int y = wires[i][1];

		g[wires[i][0]][wires[i][1]] = 1;
		g[wires[i][1]][wires[i][0]] = 1;
	}

	for (int i = 0; i < wires.size(); i++)
	{
		int x = wires[i][0];
		int y = wires[i][1];

		g[wires[i][0]][wires[i][1]] = 0;
		g[wires[i][1]][wires[i][0]] = 0;

		visit = vector<bool>(n + 1, false);

		int temp = dfs(1, g);

		answer = min(answer, abs((n - temp) - temp));

		cout << endl;

		g[wires[i][0]][wires[i][1]] = 1;
		g[wires[i][1]][wires[i][0]] = 1;
	}

	return answer;
}