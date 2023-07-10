#include <string>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

vector<vector<bool>> Visit(26, vector<bool>(26, false));
vector<vector<int>> Cost(26, vector<int>(26, INT_MAX));

int answer = INT_MAX;

void dfs(vector<vector<int>>& board, int x, int y, int cost, int dis)
{
    if (cost > Cost[x][y])
    {
        return;
    }

    if (cost < Cost[x][y])
    {
        Cost[x][y] = cost;
    }

    if ((x == board.size() - 1) && (y == board.size() - 1))
    {
        answer = min(answer, cost);

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < board.size() && ny < board.size() && !Visit[nx][ny] && !board[nx][ny])
        {
            Visit[nx][ny] = true;

            if (dis == i || (x == 0 && y == 0))
            {
                dfs(board, nx, ny, cost + 100, i);
            }

            else
            {
                dfs(board, nx, ny, cost + 600, i);
            }

            Visit[nx][ny] = false;
        }      
    }
}

int solution(vector<vector<int>> board) {

    int size = board.size();

    Visit[0][0] = true;

    dfs(board, 0, 0, 0, 0);

    return answer;
}

int main()
{
    solution({ {0, 0, 0}, {0, 0, 0}, {0, 0, 0} });

    return 0;
}