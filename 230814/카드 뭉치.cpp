#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";

	vector<string> str = goal;

	if (cards1 == goal || cards2 == goal)
	{
		answer = "Yes";

		return answer;
	}

	for (int i = 0; i < cards2.size(); i++)
	{
		auto iter = find(str.begin(), str.end(), cards2[i]);

		if (iter != str.end())
		{
			str.erase(iter);
		}
	}

	for (int i = 0; i < cards1.size(); i++)
	{
		if (i >= str.size())
		{
			break;;
		}

		if (cards1[i] != str[i])
		{
			return "No";
		}
	}

	str = goal;

	for (int i = 0; i < cards1.size(); i++)
	{
		auto iter = find(str.begin(), str.end(), cards1[i]);

		if (iter != str.end())
		{
			str.erase(iter);
		}
	}

	for (int i = 0; i < cards2.size(); i++)
	{
		if (i >= str.size())
		{
			break;;
		}

		if (cards2[i] != str[i])
		{
			return "No";
		}
	}

	answer = "Yes";

	return answer;
}

int main()
{
	solution({ "a", }, { "b", "d", "c"}, {"a", "b"});

	return 0;
}