#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 10000001;

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 10000001));

    for (int i = 0; i < fares.size(); i++)
    {
        cost[fares[i][0]][fares[i][1]] = fares[i][2];
        cost[fares[i][1]][fares[i][0]] = fares[i][2];
    }

    for (int i = 1; i <= n; i++)
    {
        cost[i][i] = 0;
    }


    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] > cost[i][k] + cost[k][j])
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (answer > cost[s][i] + cost[i][a] + cost[i][b])
        {
            answer = cost[s][i] + cost[i][a] + cost[i][b];
        }
    }

    return answer;
}