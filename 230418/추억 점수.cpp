#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;

    unordered_map<string, int> m;

    for (int i = 0; i < name.size(); i++)
    {
        m.insert(make_pair(name[i], yearning[i]));
    }

    for (int i = 0; i < photo.size(); i++)
    {
        int sum = 0;

        for (int j = 0; j < photo[i].size(); j++)
        {
            auto iter = m.find(photo[i][j]);

            if (iter != m.end())
            {
                sum += iter->second;
            }
        }

        answer.push_back(sum);
    }

    return answer;
}