#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    map<int, string> m1;
    map<string, int> m2;

    for (int i = 0; i < players.size(); i++)
    {
        m1[i] = players[i];
        m2[players[i]] = i;
    }

    for (int i = 0; i < callings.size(); i++)
    {
        int index = m2[callings[i]];

        string str = m1[index - 1];

        m1[index - 1] = callings[i];
        m1[index] = str;

        m2[callings[i]] = index - 1;
        m2[str] = index;
    }

    for (int i = 0; i < m1.size(); i++)
    {
        answer.push_back(m1[i]);
    }

    return answer;
}

int main()
{
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });

    return 0;
}