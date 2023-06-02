#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(int n) {
    long long answer = 0;

    string result;

    while (n > 0)
    {
        long long remainder = n % 3;

        if (remainder < 10)
        {
            result += to_string(remainder);
        }

        else
        {
            result += 'A' + (remainder - 10);
        }

        n /= 3;
    }

    long long a = stoll(result);

    int i = 0;

    while (a != 0)
    {
        long long remainder = a % 10;

        a /= 10;

        answer += (long long)remainder * pow(3, i);

        i++;
    }

    return answer;
}