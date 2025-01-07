#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
	int T;

	cin >> T;

	vector<int> result;

	for (int i = 0; i < T; i++)
	{
		int N;

		cin >> N;

		vector<int> v(N);
		map<int, int> m;

		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
			m[v[i]]++;
		}

		vector<int> team;

		auto iter = m.begin();
		auto iterEnd = m.end();

		vector<vector<int>> Rank(201);

		int idx = 1;

		for (int i = 0; i < N; i++)
		{
			if (m[v[i]] == 6)
			{
				Rank[v[i]].push_back(idx);

				idx++;
			}
		}

		int Winner = 0;
		int Five = 0;

		int Score = 100000000;

		for (int i = 0; i < 201; i++)
		{
			int temp = 0;

			if (Rank[i].size() == 6)
			{
				for (int j = 0; j < 4; j++)
				{
					temp += Rank[i][j];
				}

				if (temp < Score)
				{
					Score = temp;
					Winner = i;
					Five = Rank[i][4];
				}

				if (temp == Score && Five > Rank[i][4])
				{
					Winner = i;
					Five = Rank[i][4];
				}
			}
		}

		result.push_back(Winner);
	}

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}

	return 0;
}