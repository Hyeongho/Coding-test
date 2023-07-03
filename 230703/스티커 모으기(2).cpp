#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    vector<int> dp(sticker.size() + 1);

    if (sticker.size() == 1)
    {
        return sticker[0];
    }

    dp[0] = sticker[0];
    dp[1] = dp[0];

    for (int i = 2; i < sticker.size(); i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }

    dp[sticker.size() - 1] = dp[sticker.size() - 2];

    answer = *max_element(dp.begin(), dp.end());

    dp[0] = 0;

    for (int i = 1; i < sticker.size(); i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
    }

    answer = max(answer, *max_element(dp.begin(), dp.end()));

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}