#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;

    for (int i = 0; i < works.size(); i++)
    {
        pq.push(works[i]);
    }

    int i = 0;

    while (n > 0)
    {
        int a = pq.top();

        pq.pop();

        if (a > 0)
        {
            a--;
        } 

        n--;

        pq.push(a);
    }

    while (!pq.empty())
    {
        int a = pq.top();

        pq.pop();

        answer += a * a;
    }

    return answer;
}

int main()
{
    solution(3, { 1, 1 });

    return 0;
}