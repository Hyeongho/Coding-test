#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

	int idx = 0;

	int size = discount.size();

	unordered_map<string, int> m1;

	vector<pair<string, int>> v;

	for (size_t i = 0; i < want.size(); i++)
	{
		v.push_back({ want[i], number[i] });
	}

	for (int i = 0; i < discount.size() - 10; i++)
	{
		unordered_map<string, int> m2;

		bool clear = true;

		for (int j = i; j < i + 10; j++)
		{
			m2[discount[j]]++;
		}

		for (int j = 0; j < v.size(); j++)
		{
			if (m2.find(v[j].first) == m2.end())
			{
				clear = false;

				break;
			}

			if (m2[v[j].first] != v[j].second)
			{
				clear = false;

				break;
			}
		}

		if (clear)
		{
			answer++;
		}

		m2.clear();
	}

    return answer;
}