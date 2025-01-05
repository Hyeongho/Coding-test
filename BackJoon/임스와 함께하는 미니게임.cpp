#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	int N;
	char game;

	cin >> N >> game;

	int GameCount = 0;

	if (game == 'Y')
	{
		GameCount = 2;
	}

	else if (game == 'F')
	{
		GameCount = 3;
	}

	else if (game == 'O')
	{
		GameCount = 4;
	}

	set<string> s;

	for (int i = 0; i < N; i++)
	{
		string str;

		cin >> str;

		s.insert(str);
	}

	int count = s.size();
	int max = count / (GameCount - 1);

	cout << max << endl;

	return 0;
}