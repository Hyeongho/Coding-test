#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Body
{
	int Height = 0;
	int Weight = 0;
	int Index = 0;
};

bool compare(const Body& a, const Body& b)
{
	if (a.Height > b.Height && a.Weight > b.Weight)
	{
		return true;
	}

	return false;
}

int main()
{
	int N;

	cin >> N;

	vector<Body> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].Weight >> v[i].Height;
		v[i].Index = i;
	}

	vector<int> rank(N, 1);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (v[j].Weight > v[i].Weight && v[j].Height > v[i].Height)
				{
					rank[i]++;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << rank[i] << " ";
	}

	return 0;
}