#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    int len = p.size();

    vector<long long> v;

    for (int i = 0; i <= t.size() - len; i++)
    {
        string str = "";

        for (int j = i; j < i + len; j++)
        {
            str += t[j];
        }

        v.push_back(stoll(str));

        str.clear();
    }

    long long num = stoll(p);

    for (int i = 0; i < v.size(); i++)
    {
        if (num >= v[i])
        {
            answer++;
        }
    }
    
    return answer;
}

int main()
{
    solution("10203", "15");

    return 0;
}