#include <string>
#include <vector>
#include <queue>
#include <limits.h>
#include <math.h>

using namespace std;

int bfs(int sources, int destination, vector<vector<int>>& roads)
{
    queue<pair<int, int>> q;

    q.push({ destination , 0 });

    vector<bool> visit(100001, false);

    visit[destination] = true;

    int result = INT_MAX;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;

        q.pop();

        if (cur == sources)
        {
            result = min(result, cost);
        }

        for (int i = 0; i < roads[cur].size(); i++)
        {
            if (!visit[roads[cur][i]])
            {
                visit[roads[cur][i]] = true;
                q.push({ roads[cur][i], cost + 1 });
            }
        }
    }

    return result;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<vector<int>> v(100001);

    for (int i = 0; i < roads.size(); i++)
    {
        v[roads[i][0]].push_back(roads[i][1]);
        v[roads[i][1]].push_back(roads[i][0]);
    }

    for (int i = 0; i < sources.size(); i++)
    {
        if (sources[i] == destination)
        {
            answer.push_back(0);
        }

        else
        {
            int result = bfs(sources[i], destination, v);

            if (result == INT_MAX)
            {
                answer.push_back(-1);
            }

            else
            {
                answer.push_back(result);
            }
        }
    }

    return answer;
}

int main()
{
    solution(3, { {1, 2}, {2, 3} }, { 2, 3 }, 1);

    return 0;
}