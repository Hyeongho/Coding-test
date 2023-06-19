#include <string>
#include <vector>
#include <math.h>

using namespace std;

bool check(long long l)
{
    while (l)
    {
        if (l % 5 == 2)
        {
            return false;
        }

        if (l / 5 == 2)
        {
            return false;
        }

        l /= 5;
    }

    return true;
}

int solution(int n, long long l, long long r) {
    int answer = 0;

    long long start = l - 1;
    long long end = r - 1;

    while (start <= end)
    {
        if (check(start))
        {
            answer++;
        }

        start++;
    }

    return answer;
}