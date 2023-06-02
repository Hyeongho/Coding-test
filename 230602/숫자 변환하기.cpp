#include <string>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;

    vector<int> v(1000001, 0);
    queue<int> q;

    q.push(x);
    v[x]++;

    while (!q.empty())
    {
        int cur = q.front();

        if (cur == y)
        {
            answer = v[cur];

            break;
        }

        q.pop();

        int dir[3] = { cur + n, cur * 2, cur * 3 };

        for (int i = 0; i < 3; i++)
        {
            int dx = dir[i];

            if (dx > y || v[dx] != 0)
            {
                continue;
            }

            q.push(dx);
            v[dx] = v[cur] + 1;
        }
    }
    
    return answer;
}

int main()
{
    solution(1, 11, 2);

    return 0;
}