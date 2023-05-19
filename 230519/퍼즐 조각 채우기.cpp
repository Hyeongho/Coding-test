#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<bool>> visited(53, vector<bool>(53, false));

void dfs(int y, int x, vector<vector<int>>& game_board, vector<pair<int, int>>& puzzle)
{
    if (visited[y][x])
    {
        return;
    }

    if (game_board[y][x] == 0)
    {
        return;
    }

    visited[y][x] = true;

    puzzle.push_back({ y, x });

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= game_board.size() || nx >= game_board.size())
        {
            continue;
        }

        dfs(ny, nx, game_board, puzzle);
    }
}

bool solve(vector<vector<int>>& game_board, vector<pair<int, int>> puzzle)
{
    int size = game_board.size();

    for (int r = -size + 1; r < size; r++)
    {
        for (int c = -size + 1; c < size; c++)
        {
            vector<pair<int, int>> fitblock;

            auto iter1 = puzzle.begin();
            auto iterEnd1 = puzzle.end();

            for (; iter1 != iterEnd1; iter1++)
            {
                fitblock.push_back({ (*iter1).first + r, (*iter1).second + c });
            }

            int count = 0;

            for (int i = 0; i < fitblock.size(); i++)
            {
                pair<int, int> cur = fitblock[i];

                if (cur.first < 0 || cur.second < 0 || cur.first >= size || cur.second >= size)
                {
                    break;
                }

                if (game_board[cur.first][cur.second] == 1)
                {
                    break;
                }

                count++;
            }

            if (count == fitblock.size())
            {
                bool fit = true;

                auto iter2 = fitblock.begin();
                auto iterEnd2 = fitblock.end();

                for (; iter2 != iterEnd2; iter2++)
                {
                    game_board[(*iter2).first][(*iter2).second] = 1;
                }

                for (int i = 0; i < fitblock.size(); i++)
                {
                    pair<int, int> cur = fitblock[i];

                    for (int j = 0; j < 4; j++)
                    {
                        int ny = cur.first + dy[j];
                        int nx = cur.second + dx[j];

                        if (ny < 0 || nx < 0 || ny >= size || nx >= size)
                        {
                            continue;
                        }

                        if (game_board[ny][nx] == 0)
                        {
                            fit = false;
                            break;
                        }
                    }

                    if (fit == false)
                    {
                        break;
                    }
                }

                if (fit == false)
                {
                    auto iter3 = fitblock.begin();
                    auto iterEnd3 = fitblock.end();

                    for (; iter3 != iterEnd3; iter3++)
                    {
                        game_board[(*iter3).first][(*iter3).second] = 0;
                    }
                }

                else
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;

    vector<vector<pair<int, int>>> p;

    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table[0].size(); j++)
        {
            if (table[i][j] == 1)
            {
                vector<pair<int, int>> result;

                dfs(i, j, table, result);

                if (result.size())
                {
                    p.push_back(result);
                }
            }
        }
    }

    vector<vector<int>> rot(table.size(), vector<int>(table.size(), 0));

    vector<bool> pice(p.size(), false);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < table.size(); j++)
        {
            for (int k = 0; k < table.size(); k++)
            {
                rot[j][k] = game_board[k][table.size() - j - 1];
            }
        }

        for (int j = 0; j < p.size(); j++)
        {
            if (pice[j] == 0 && solve(rot, p[j]))
            {
                answer += p[j].size();

                pice[j] = 1;
            }
        }

        for (int j = 0; j < table.size(); j++)
        {
            for (int k = 0; k < table.size(); k++)
            {
                game_board[j][k] = rot[j][k];
            }
        }
    }

    return answer;
}