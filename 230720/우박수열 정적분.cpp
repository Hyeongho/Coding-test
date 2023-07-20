#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;

    vector<pair<int, int>> v1;

    int result = k;

    v1.push_back({ 0, k });

    int idx = 1;

    while (result != 1)
    {
        if (result % 2 == 0)
        {
            result /= 2;
        }

        else
        {
            result = result * 3 + 1;
        }

        v1.push_back({ idx, result });

        idx++;
    }

    vector<double> v2;

    for (int i = 0; i < k; i++)
    {
        v2.push_back(((double)v1[i].second + v1[i + 1].second) / 2);
    }

    for (int i = 0; i < ranges.size(); i++)
    {
        int start = ranges[i][0];
        int end = v1.size() - 1 + ranges[i][1];

        double sum = 0;

        for (int j = start; j < end; j++)
        {
            sum += (double)(v1[j].second + v1[j + 1].second) / 2;
        }

        if (start > end)
        {
            answer.push_back(-1.0);
        }

        else
        {
            answer.push_back(sum);
        }
    }

    return answer;
}

int main()
{
    solution(5, { {0, 0}, {0, -1}, {2, -3}, {3, -3} });

    return 0;
}