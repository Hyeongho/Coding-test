#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    int cx = characterX * 2;
    int cy = characterY * 2;
    int ix = itemX * 2;
    int iy = itemY * 2;

    vector<vector<int>> borad(100, vector<int>(100));

    for (int i = 0; i < rectangle.size(); i++)
    {
        for (int j = 0; j < rectangle[i].size(); j++)
        {
            rectangle[i][j] = rectangle[i][j] * 2;
        }

        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];

        for (int y = y1; y <= y2; y++)
        {
            for (int x = x1; x <= x2; x++)
            {
                borad[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < rectangle.size(); i++)
    {
        int x1 = rectangle[i][0];
        int y1 = rectangle[i][1];
        int x2 = rectangle[i][2];
        int y2 = rectangle[i][3];

        for (int y = y1 + 1; y < y2; y++)
        {
            for (int x = x1 + 1; x < x2; x++)
            {
                borad[y][x] = 0;
            }
        }
    }

    queue<pair<int, int>> q;

    q.emplace(cx, cy);

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        if (x == ix && y == iy)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (borad[ny][nx] == 1)
            {
                q.emplace(nx, ny);
                borad[ny][nx] = borad[y][x] + 1;
            }
        }
    }

    answer = borad[iy][ix] / 2;

    return answer;
}