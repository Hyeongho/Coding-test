#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<bool>> visit;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<string> maps) {
    int answer = 0;

    int startx = 0;
    int starty = 0;

    int lx = 0;
    int ly = 0;

    int endx = 0;
    int endy = 0;

    vector<vector<int>> visit(100, vector<int>(100));

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                startx = j;
                starty = i;
            }

            else if (maps[i][j] == 'L')
            {
                lx = j;
                ly = i;
            }

            else if (maps[i][j] == 'E')
            {
                endx = j;
                endy = i;
            }
        }
    }

    queue<pair<int, int>> q;

    q.push({ startx, starty });

    int cx = startx;
    int cy = starty;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x == lx && y == ly)
        {
            cx = lx;
            cy = ly;

            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dx[i];
            int nexty = y + dy[i];

            if (nextx >= maps[0].size() || nexty >= maps.size() || nextx < 0 || nexty < 0)
            {
                continue;
            }

            if (!visit[nexty][nextx] && maps[nexty][nextx] != 'X')
            {
                q.push({ nextx, nexty });

                visit[nexty][nextx] = visit[y][x] + 1;
            }
        }
    }

    if (cx != lx && cy != ly)
    {
        return -1;
    }

    answer += visit[cy][cx];

    auto iter = visit.begin();
    auto iterEnd = visit.end();

    for (; iter != iterEnd; iter++)
    {
        fill(iter->begin(), iter->end(), 0);
    }

    while (!q.empty())
    {
        q.pop();
    }

    q.push({ cx, cy });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x == endx && y == endy)
        {
            cx = endx;
            cy = endy;

            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextx = x + dx[i];
            int nexty = y + dy[i];

            if (nextx >= maps[0].size() || nexty >= maps.size() || nextx < 0 || nexty < 0)
            {
                continue;
            }

            if (!visit[nexty][nextx] && maps[nexty][nextx] != 'X')
            {
                q.push({ nextx, nexty });

                visit[nexty][nextx] = visit[y][x] + 1;
            }
        }
    }

    if (cx != endx && cy != endy)
    {
        return -1;
    }

    answer += visit[cy][cx];

    return answer;
}

int main()
{
    solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });

    return 0;
}