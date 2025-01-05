#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Vowel(char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}

	else
	{
		return false;
	}
}

int main()
{
	string str;
	vector<string> v;

	while (true)
	{
		getline(cin, str);

		if (str == "end")
		{
			break;
		}

		v.push_back(str);
	}

	for (int i = 0; i < v.size(); i++)
	{
		int ConsonantCount = 0;
		int VowelCount = 0;

		bool IsAcceptable = true;
		bool IsVowel = false;

		for (int j = 0; j < v[i].size(); j++)
		{
			char cur = v[i][j];

			if (Vowel(cur))
			{
				VowelCount++;
				IsVowel = true;
				ConsonantCount = 0;
			}

			else
			{
				VowelCount = 0;
				ConsonantCount++;
			}

			if (VowelCount >= 3 || ConsonantCount >= 3)
			{
				IsAcceptable = false;

				break;
			}

			if (j > 0 && cur == v[i][j - 1] && cur != 'e' && cur != 'o')
			{
				IsAcceptable = false;

				break;
			}
		}

		if (!IsVowel)
		{
			IsAcceptable = false;
		}

		if (IsAcceptable)
		{
			cout << "<" << v[i] << "> is acceptable." << endl;
		}

		else
		{
			cout << "<" << v[i] << "> is not acceptable." << endl;
		}
	}

	return 0;
}