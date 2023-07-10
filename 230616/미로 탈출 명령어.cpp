#include <string>
#include <vector>
#include <math.h>
#include <stack>
#include <tuple>

using namespace std;

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };

char dis[4] = { 'd', 'l', 'r', 'u' };

char result[2501];

bool check = false;

void dfs(int n, int m, int x, int y, int r, int c, int k, int cnt, string& answer)
{
    if (check)
    {
        return;
    }

    if (x == r && y == c && cnt == k)
    {
        answer = result;

        check = true;

        return;
    }

    if (cnt + abs(x - r) + abs(y - c) > k)
    {
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || ny < 1 || nx > n || ny > m)
        {
            continue;
        }

        result[cnt] = dis[i];

        dfs(n, m, nx, ny, r, c, k, cnt + 1, answer);

        result[cnt] = ' ';
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {

    string answer;

    int move1 = abs(r - x) + abs(c - y);

    int move2 = abs(k - move1);

    vector<vector<bool>> visit(51, vector<bool>(51, false));

    if ((move2 % 2 == 1) || k < move1)
    {
        return "impossible";
    }

    dfs(n, m, x, y, r, c, k, 0, answer);

    return answer;
}

int main()
{
    solution(3, 4, 2, 3, 3, 1, 5);

    return 0;
}