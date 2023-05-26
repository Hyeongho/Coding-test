#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s)
    {
        return { -1 };
    }

    for (int i = 0; i < n; i++)
    {
        answer.push_back(s / n);
    }

    if (s % n != 0)
    {
        for (int i = 0; i < s % n; i++)
        {
            answer[n - 1 - i]++;
        }
    }

    return answer;
}

int main()
{
    solution(2, 9);

    return 0;
}