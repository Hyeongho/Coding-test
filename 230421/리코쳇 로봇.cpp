#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution(vector<string> board) {
    int answer = -1;

    int x = board[0].size();
    int y = board.size();

    vector<vector<int>> v(y, vector<int>(x, -1));

    queue<pair<int, int>> q;

    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (board[i][j] == 'R')
            {
                q.push({ j, i });
            }
        }
    }

    v[q.front().second][q.front().first] = 0;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cur.first;
            int ny = cur.second;

            while (1)
            {
                if (nx < 0 || ny < 0 || nx >= x || ny >= y)
                {
                    break;
                }

                if (board[ny][nx] == 'D')
                {
                    break;
                }

                nx += dx[i];
                ny += dy[i];
            }

            nx -= dx[i];
            ny -= dy[i];

            if (board[ny][nx] == 'G')
            {
                return v[cur.second][cur.first] + 1;
            }

            if (v[ny][nx] >= 0)
            {
                continue;
            }

            v[ny][nx] = v[cur.second][cur.first] + 1;

            q.push({ nx, ny });
        }
    }

    return answer;
}

int main()
{
    solution({ "...D..R", ".D.G...", "....D.D", "D....D.", "..D...." });

    return 0;
}