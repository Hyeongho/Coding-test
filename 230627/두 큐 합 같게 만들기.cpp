#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum = 0;
    long long sum1 = 0;
    long long sum2 = 0;

    for (int i = 0; i < queue1.size(); i++)
    {
        sum1 += (long long)queue1[i];
        sum2 += (long long)queue2[i];
    }

    sum = sum1 + sum2;

    queue<int> q1;
    queue<int> q2;

    for (int i = 0; i < queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }

    int idx = 0;

    while (idx <= queue1.size() * 2)
    {
        if (sum1 == sum2)
        {
            return answer;
        }

        answer++;

        if (sum1 > sum2)
        {
            int a = q1.front();
            q1.pop();
            q2.push(a);

            sum1 -= a;
            sum2 += a;

            idx++;
        }

        else
        {
            int a = q2.front();
            q2.pop();
            q1.push(a);

            sum2 -= a;
            sum1 += a;

            idx++;
        }
    }

    return -1;
}