#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_map<int, int> m1;
    unordered_map<int, int> m2;

    for (int i = 0; i < topping.size(); i++)
    {
        m1[topping[i]]++;
    }

    for (int i = 0; i < topping.size(); i++)
    {
        m1[topping[i]]--;
        m2[topping[i]]++;

        if (m1[topping[i]] == 0)
        {
            m1.erase(topping[i]);
        }

        if (m1.size() == m2.size())
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    solution({ 1, 2, 1, 3, 1, 4, 1, 2 });

    return 0;
}