#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Medal
{
	int K = 0;
	int Gold = 0;
	int Silver = 0;
	int Bronze = 0;
};

bool compare(const Medal& a, const Medal& b)
{
	if (a.Gold != b.Gold)
	{
		return a.Gold > b.Gold;
	}

	if (a.Silver != b.Silver)
	{
		return a.Silver > b.Silver;
	}

	return a.Bronze > b.Bronze;
}

int main()
{
	int N;
	int K;

	cin >> N >> K;

	vector<Medal> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].K >> v[i].Gold >> v[i].Silver >> v[i].Bronze;
	}

	sort(v.begin(), v.end(), compare);

	vector<int> rank(N);

	rank[0] = 1;

	for (int i = 1; i < N; i++) 
	{
		if (compare(v[i - 1], v[i]) || compare(v[i], v[i - 1]))
		{
			rank[i] = i + 1;
		}

		else
		{
			rank[i] = rank[i - 1];
		}
	}

	for (int i = 0; i < N; i++) 
	{
		if (v[i].K == K)
		{
			cout << rank[i] << endl;

			break;
		}
	}

	return 0;
}