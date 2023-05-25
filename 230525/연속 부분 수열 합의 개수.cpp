#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

    int len = 1;

    set<int> s;

    while (len <= elements.size())
    {
        for (int i = 0; i < elements.size(); i++)
        {
            int sum = 0;

            for (int j = i; j < i + len; j++)
            {
                if (j >= elements.size())
                {
                    sum += elements[j - elements.size()];
                }

                else
                {
                    sum += elements[j];
                }
            }

            s.insert(sum);
        }
    }

    answer = s.size();

    return answer;
}