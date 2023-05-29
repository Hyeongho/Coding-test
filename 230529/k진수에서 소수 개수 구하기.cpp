#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Prime(string p)
{
    long long a = stoll(p);

    if (a <= 1)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(a); i++) 
    {
        if (a % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string result;

    while (n > 0)
    {
        int remainder = n % k;

        if (remainder < 10)
        {
            result += to_string(remainder);
        }

        else
        {
            result += 'A' + (remainder - 10);
        }

        n /= k;
    }

    reverse(result.begin(), result.end());

    //int a = stoi(result);

    string p = "";

    for (int i = 0; i < result.size(); i++)
    {       
        if (result[i] == '0' && !p.empty())
        {
            if (Prime(p))
            {
                answer++;
            }

            p = "";
        }

        p += result[i];
    }

    if (!p.empty() && Prime(p))
    {
        answer++;
    }

    return answer;
}

int main()
{
    solution(437674, 3);

    return 0;
}