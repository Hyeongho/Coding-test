#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<>> pq;

    int sum = 0;

    for (int i = 0; i < enemy.size(); i++)
    {
        pq.push(enemy[i]);

        if (pq.size() > k)
        {
            sum += pq.top();

            pq.pop();
        }

        if (sum > n)
        {
            return i;
        }
    }

    return enemy.size();
}

int main()
{
    solution(7, 3, { 4, 2, 4, 5, 3, 3, 1 });

    return 0;
}