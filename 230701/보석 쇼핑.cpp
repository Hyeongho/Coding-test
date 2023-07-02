#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);

    set<string> s(gems.begin(), gems.end());
    unordered_map<string, int> m;

    int start = 0;
    int end = 0;

    int min = 0;

    for (int i = 0; i < gems.size(); i++)
    {
        m[gems[i]]++;

        if (m.size() == s.size())
        {
            break;
        }

        end++;
    }

    min = end - start;

    answer[0] = start + 1;
    answer[1] = end + 1;

    while (end < gems.size())
    {
        string str = gems[start];

        m[str]--;

        start++;

        if (m[str] == 0)
        {
            end++;

            while (end < gems.size())
            {
                m[gems[end]]++;          

                if (str == gems[end])
                {
                    break;
                }

                end++;
            }

            if (end == gems.size())
            {
                break;
            }
        }

        if (min > end - start)
        {
            min = end - start;

            answer[0] = start + 1;
            answer[1] = end + 1;
        }
    }

    return answer;
}

int main()
{
    solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });

    return 0;
}