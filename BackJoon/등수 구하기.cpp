#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;
	int NewScore;
	int P;

	cin >> N >> NewScore >> P;

	if (N == 0)
	{
		cout << 1 << endl;

		return 0;
	}

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int Rank = 1;
	int Count = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (NewScore < v[i])
		{
			Rank++;
		}

		else
		{
			break;
		}

		Count++;
	}

	if (NewScore <= v[N - 1] && N == P)
	{
		cout << -1 << endl;

		return 0;
	}

	cout << Rank << endl;

	return 0;
}