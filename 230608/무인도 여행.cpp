#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<bool>> visit(100, (vector<bool>(100, false)));

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int x, int y, vector<string> maps)
{
	int cnt = 0;

	visit[y][x] = true;

	stack<pair<int, int>> s;

	s.push({ x, y });

	cnt += maps[y][x] - '0';

	while (!s.empty())
	{
		int curx = s.top().first;
		int cury = s.top().second;

		s.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextx = curx + dx[i];
			int nexty = cury + dy[i];

			if (nextx >= maps[0].size() || nexty >= maps.size() || nextx < 0 || nexty < 0)
			{
				continue;
			}

			if (!visit[nexty][nextx] && maps[nexty][nextx] != 'X')
			{
				s.push({ nextx, nexty });

				cnt += maps[nexty][nextx] - '0';

				visit[nexty][nextx] = true;
			}
		}
	}

	return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;

	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].size(); j++)
		{
			if (maps[i][j] != 'X' && !visit[i][j])
			{
				answer.push_back(dfs(j, i, maps));
			}		
		}
	}

	if (answer.empty())
	{
		return { -1 };
	}

	sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
	solution({ "XXX","XXX","XXX" });

	return 0;
}