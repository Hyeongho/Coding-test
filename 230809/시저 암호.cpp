#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			for (int j = 0; j < n; j++)
			{
				if (s[i] == 'z')
				{
					s[i] = 'a';
				}

				else if (s[i] == 'Z')
				{
					s[i] = 'A';
				}
				
				else
				{
					s[i] = s[i] + 1;
				}
			}
		}
	}

    return s;
}