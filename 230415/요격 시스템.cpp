#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }

    else
    {
        return a[1] < b[1];
    }
}

int solution(vector<vector<int>> targets) {
    
    int answer = 1;

    sort(targets.begin(), targets.end(), compare);

    auto iter = targets.begin();
    auto iterEnd = targets.end();

    int last = targets[0][1];

    for (iter; iter != iterEnd; iter++)
    {
        if (last > (*iter)[0] && last <= (*iter)[1])
        {
            continue;
        }

        else
        {
            last = (*iter)[1];

            answer++;

            continue;
        }
    }

    return answer;
}

int main()
{
    solution({ {4, 5}, {4, 8}, {10, 14}, {11, 13}, {5, 12}, {3, 7}, {1, 4} });

    return 0;
}