#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int dfs(int _i, int _j, const char c, vector<string> board)
{
    int win = 0;

    for (int i = 0; i < 8; i++)
    {
        int idx = 0;

        for (int j = 0; j < 3; j++)
        {
            int nexti = _i + (v[i].second * idx);
            int nextj = _j + (v[i].first * idx);

            if (nexti >= 3 || nextj >= 3 || nexti < 0 || nextj < 0)
            {
                break;
            }

            else
            {
                if (board[nexti][nextj] != c)
                {
                    break;
                }
            }

            idx++;
        }

        if (idx == 3)
        {
            win++;
        }
    }

    return win;
}

int solution(vector<string> board) {
    int answer = 0;

    v.push_back({ 1, 0 });
    v.push_back({ -1, 0 });
    v.push_back({ 1, -1 });
    v.push_back({ 0, 1 });
    v.push_back({ 0, -1 });
    v.push_back({ -1, 1 });
    v.push_back({ 1, 1 });
    v.push_back({ -1, -1 });

    int x = 0;
    int o = 0;
    int winx = 0;
    int wino = 0;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                o++;
            }

            else if (board[i][j] == 'X')
            {
                x++;
            }
        }
    }

    if (x > o || o > x + 1)
    {
        return 0;
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (board[i][j] == 'O')
            {
                wino += dfs(i, j, 'O', board);

                if (winx && wino)
                {
                    return 0;
                }
            }

            else if (board[i][j] == 'X')
            {
                winx += dfs(i, j, 'X', board);

                if (winx && wino)
                {
                    return 0;
                }
            }
        }
    }

    if (((winx == wino) && (wino == 0)) || ((winx / 2 == 1) && (o == x)) || ((wino / 2 == 1) && (x + 1 == o)) || ((wino / 2 == 2) && (o == 5)))
    {
        return 1;
    }

    return answer;
}

int main()
{
    solution({ "OOO", "...", "XXX" });

    return 0;
}