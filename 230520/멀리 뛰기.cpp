#include <string>
#include <vector>

using namespace std;

long long solution(int n) {

    long long answer = 0;

    int dp[2001];

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1234567;
    }

    answer = dp[n];

    return answer;
}

int main()
{
    solution(4);

    return 0;
}