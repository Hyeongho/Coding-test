#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Col = 0;
int Begin = 0;
int End = 0;

bool compare(vector<int>& a, vector<int>& b)
{
    if (a[Col - 1] < b[Col - 1])
    {
        return true;
    }

    else if (a[Col - 1] == b[Col - 1])
    {
        if (a[0] < b[0])
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    return false;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;

    Col = col;
    Begin = row_begin;
    End = row_end;

    sort(data.begin(), data.end(), compare);

    for (int i = row_begin; i <= row_end; i++)
    {
        int result = 0;

        for (int j = 0; j < data[i].size(); j++)
        {
            result += data[i][j] % i;
        }

        answer ^= result;
    }

    return answer;
}