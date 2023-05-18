#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str = "AEIOU";

void dfs(string word, int len, vector<string>& dic)
{
    if (len == 6)
    {
        return;
    }

    else
    {
        dic.push_back(word);
    }

    for (int i = 0; i < str.size(); i++)
    {
        dfs(word + str[i], len + 1, dic);
    }
}

int solution(string word) {
    int answer = 0;

    vector<string> dic;

    dfs("", 0, dic);

    auto iter = find(dic.begin(), dic.end(), word);

    if (iter != dic.end())
    {
        answer = iter - dic.begin();
    }

    return answer;
}

int main()
{
    solution("AAAAE");

    return 0;
}