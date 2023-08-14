#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

	unordered_map<char, int> m;

	for (int i = 0; i < s.size(); i++)
	{
		auto iter = m.find(s[i]);

		if (iter == m.end())
		{
			m.insert(make_pair(s[i], i));

			answer.push_back(-1);
		}

		else
		{
			int idx = i - m[s[i]];

			answer.push_back(idx);

			m[s[i]] = i;
		}
	}

    return answer;
}