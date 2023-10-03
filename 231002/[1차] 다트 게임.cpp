#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    stack<int> s;

    vector<int> v;

    int idx = 0;
    int score = 0;

    for (int i = 0; i < dartResult.size(); i++)
    {
        if (dartResult[i] == 'S')
        {

        }

        else if (dartResult[i] == 'D')
        {
            v[idx] = score * score;
        }

        else if (dartResult[i] == 'T')
        {
            v[idx] = score * score * score;
        }

        else if (dartResult[i] == '*')
        {
            if (v.size() == 1)
            {
                v[idx] *= 2;
            }

            else
            {
                v[idx] *= 2;
                v[idx - 1] *= 2;
            }
        }

        else if (dartResult[i] == '#')
        {
            v[idx] *= -1;
        }

        else
        {
            if (dartResult[i + 1] >= '0' && dartResult[i + 1] <= '9')
            {
                string str = dartResult.substr(i, 2);

                score = stoi(str);

                v.push_back(score);

                idx = v.size() - 1;

                i++;
            }

            else
            {
                score = dartResult[i] - '0';

                v.push_back(score);

                idx = v.size() - 1;
            }
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        answer += v[i];
    }

    return answer;
}

int main()
{
    solution("1D2S#10S");

    return 0;
}