#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<string> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	string result;

	int kbs1 = 0;
	int kbs2 = 0;

	for (int i = 0; i < N; i++)
	{
		if (v[i] == "KBS1")
		{
			kbs1 = i;
			break;
		}
	}

	for (int i = 0; i < kbs1; i++)
	{
		result += "1";
	}

	for (int i = 0; i < kbs1; i++)
	{
		result += "4";
	}

	for (int i = 0; i < N; i++)
	{
		if (v[i] == "KBS2")
		{
			kbs2 = i;

			break;
		}
	}

	if (kbs2 < kbs1)
	{
		kbs2++;
	}

	for (int i = 0; i < kbs2; i++)
	{
		result += "1";
	}

	for (int i = 0; i < kbs2 - 1; i++)
	{
		result += "4";
	}

	cout << result;

	return 0;
}