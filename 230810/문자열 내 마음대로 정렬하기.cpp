#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(string& a, string& b)
{
    if (a[N] < b[N])
    {
        return true;
    }

    else if (a[N] == b[N])
    {
        if (a <= b)
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

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    N = n;

    sort(strings.begin(), strings.end(), compare);
    
    return strings;
}