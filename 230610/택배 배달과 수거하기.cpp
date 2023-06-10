#include <string>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    stack<long long> d;
    stack<long long> p;

    for (int i = 0; i < n; i++)
    {
        d.push(deliveries[i]);
        p.push(pickups[i]);
    }

    while (!d.empty() && d.top() == 0)
    {
        d.pop();
    }

    while (!p.empty() && p.top() == 0)
    {
        p.pop();
    }

    while (true)
    {
        if (d.empty() && p.empty())
        {
            break;
        }

        answer += (long long)max(d.size() * 2, p.size() * 2);

        long long box = 0;

        while (!d.empty() && box <= cap)
        {
            if (d.top() + box <= cap)
            {
                box += d.top();
            }

            else
            {
                d.top() -= (cap - box);

                break;
            }

            d.pop();
        }

        box = 0;

        while (!p.empty() && box <= cap)
        {
            if (p.top() + box <= cap)
            {
                box += p.top();
            }

            else
            {
                p.top() -= (cap - box);

                break;
            }

            p.pop();
        }
    }

    return answer;
}