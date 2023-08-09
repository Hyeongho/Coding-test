#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    sort(number.begin(), number.end());

    vector<bool> temp(number.size(), true);

    for (int i = 0; i < number.size() - 3; i++)
    {
        temp[i] = false;
    }

    do
    {
        int result = 0;

        for (int i = 0; i < number.size(); i++)
        {
            if (temp[i])
            {
                result += number[i];
            }
        }

        if (result == 0)
        {
            answer++;
        }

    } while (next_permutation(temp.begin(), temp.end()));

    return answer;
}