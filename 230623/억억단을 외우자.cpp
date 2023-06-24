#include <string>
#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    vector<int> dp(e + 1, 0);
    vector<int> arr(e + 1, 0);

    for (int i = 1; i <= e; i++)
    {
        dp[i] = i;
    }

    for (int i = 2; i <= e; i++)
    {
        for (int j = 1; j <= e; j++)
        {
            if (i * j > e)
            {
                break;
            }

            arr[i * j]++;
        }
    }

    for (int i = e - 1; i >= 0; i--)
    {
        if (arr[i] >= arr[dp[i + 1]])
        {
            dp[i] = i;
        }

        else
        {
            dp[i] = dp[i + 1];
        }
    }

    for (int i = 0; i < starts.size(); i++)
    {
        answer.push_back(dp[starts[i]]);
    }

    return answer;
}

int main()
{
    solution(8, { 1, 3, 7 });

    return 0;
}