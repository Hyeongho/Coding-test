#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long f(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * f(n - 1);
}

vector<int> solution(int n, long long k) {
    vector<int> answer;

    vector<long long> v;
    vector<long long> combination;

    for (int i = 0; i < n; i++)
    {
        v.push_back((long long)i + 1);
    }

    long long idx = 0;

    int num;

    while (0 < n)
    {
        idx = f(n) / n;

        num = (int)((k - 1) / idx);

        answer.push_back(v[num]);

        v.erase(v.begin() + num);

        n--;

        k %= idx;

        if (k == 0)
        {
            k = idx;
        }
    }

    return answer;
}

int main()
{
    solution(3, 5);

    return 0;
}