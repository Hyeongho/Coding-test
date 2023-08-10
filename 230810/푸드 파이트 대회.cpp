#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    vector<int> v;

    for (int i = 1; i < food.size(); i++)
    {
        if (food[i] / 2 == 0)
        {
            v.push_back(0);
        }

        else
        {
            v.push_back(food[i] / 2);
        }
    }

    vector<int> v1;

    int idx = 1;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i]; j++)
        {
            v1.push_back(idx);
        }

        idx++;
    }

    for (int i = 0; i < v1.size(); i++)
    {
        answer += to_string(v1[i]);
    }

    answer += '0';

    for (int i = v1.size() - 1; i >= 0; i--)
    {
        answer += to_string(v1[i]);
    }

    return answer;
}

int main()
{
    solution({ 1, 3, 4, 6 });

    return 0;
}