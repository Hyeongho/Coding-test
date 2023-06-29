#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool Check(const string& a, const string& b)
{
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (b[i] == '*' || a[i] == b[i])
			{
				continue;
			}

			return false;
		}
	}

	else
	{
		return false;
	}

	return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

	sort(user_id.begin(), user_id.end());

	set<string> s;

	do
	{
		vector<string> v;
		string str = "";

		for (int i = 0; i < banned_id.size(); i++)
		{
			if (Check(user_id[i], banned_id[i]))
			{
				v.push_back(user_id[i]);
			}
		}

		if (v.size() == banned_id.size())
		{
			sort(v.begin(), v.end());

			for (int i = 0; i < v.size(); i++)
			{
				str += v[i];
			}

			s.insert(str);
		}

	} while (next_permutation(user_id.begin(), user_id.end()));

	answer = s.size();

    return answer;
}

int main()
{
	solution({ "frodo", "fradi", "crodo", "abc123", "frodoc" }, { "fr*d*", "abc1**" });

	return 0;
}