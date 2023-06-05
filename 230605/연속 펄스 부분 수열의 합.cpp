#include <string>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = LONG_MIN;

    vector<int> v1;
    vector<int> v2;

    vector<long long> dp1(sequence.size());
    vector<long long> dp2(sequence.size());

    int a = -1;

    for (int i = 0; i < sequence.size(); i++)
    {
        v1.push_back(sequence[i] * a);

        a *= -1;
    }

    a = 1;

    for (int i = 0; i < sequence.size(); i++)
    {
        v2.push_back(sequence[i] * a);

        a *= -1;
    }

    dp1[0] = v1[0];
    dp2[0] = v2[0];

    for (int i = 1; i < sequence.size(); i++)
    {
        dp1[i] = max(dp1[i - 1] + (long long)v1[i], (long long)v1[i]);

        answer = max(dp1[i], answer);
    }

    for (int i = 1; i < sequence.size(); i++)
    {
        dp2[i] = max(dp2[i - 1] + (long long)v2[i], (long long)v2[i]);

        answer = max(dp2[i], answer);
    }

    if (sequence.size() == 1)
    {
        answer = max(v1[0], v2[0]);
    }

    return answer;
}

int main()
{
    solution({ 2, 3, -6, 1, 3, -1, 2, 4 });

    return 0;
}