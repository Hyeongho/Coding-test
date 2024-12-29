#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
	string str;
	
	vector<int> v(26, 0);

	cin >> str;

	transform(str.begin(), str.end(), str.begin(), ::toupper);

	for (int i = 0; i < str.size(); i++)
	{
		v[str[i] - 'A']++;
	}

	int max = 0;

	char result = '?';

	for (int i = 0; i < 26; i++)
	{
		if (v[i] > max)
		{
			max = v[i];

			result = 'A' + i;
		}

		else if (v[i] == max)
		{
			result = '?';
		}
	}

	cout << result << endl;

	return 0;
}