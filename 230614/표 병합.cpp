#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> list(51, vector<string>(51, "EMPTY"));
vector<vector<pair<int, int>>> link(51, vector<pair<int, int>>(51));

vector<string> solution(vector<string> commands) {
    vector<string> answer;

	for (int i = 0; i < link.size(); i++)
	{
		for (int j = 0; j < link[i].size(); j++)
		{
			link[i][j].first = i;
			link[i][j].second = j;
		}
	}

	for (int i = 0; i < commands.size(); i++)
	{
		vector<string> v;

		stringstream ss(commands[i]);
		
		string str;

		while (ss >> str)
		{
			v.push_back(str);
		}

		if (v[0] == " ")
		{
			continue;
		}

		else if (v[0] == "UPDATE")
		{
			if (v.size() == 4)
			{
				int r = stoi(v[1]);
				int c = stoi(v[2]);

				int pr = link[r][c].first;
				int pc = link[r][c].second;

				list[pr][pc] = v[3];
			}

			else
			{
				for (int j = 0; j < list.size(); j++)
				{
					for (int k = 0; k < list[j].size(); k++)
					{
						if (list[j][k] ==  v[1])
						{
							list[j][k] = v[2];
						}
					}
				}
			}
		}

		else if (v[0] == "MERGE")
		{
			int r1 = stoi(v[1]);
			int c1 = stoi(v[2]);

			int r2 = stoi(v[3]);
			int c2 = stoi(v[4]);

			int pr1 = link[r1][c1].first;
			int pc1 = link[r1][c1].second;

			int pr2 = link[r2][c2].first;
			int pc2 = link[r2][c2].second;

			if (pr1 == pr2 && pc1 == pc2)
			{
				continue;
			}

			for (int j = 0; j < list.size(); j++)
			{
				for (int k = 0; k < list[j].size(); k++)
				{
					if (link[j][k].first == pr2 && link[j][k].second == pc2)
					{
						link[j][k].first = pr1;
						link[j][k].second = pc1;
					}
				}
			}

			string str1 = list[pr1][pc1];
			string str2 = list[pr2][pc2];

			if (str1 == "EMPTY" && str2 != "EMPTY")
			{
				list[pr1][pc1] = list[pr2][pc2];
			}

			else
			{
				list[pr2][pc2] = list[pr1][pc1];
			}
		}

		else if (v[0] == "UNMERGE")
		{
			int r = stoi(v[1]);
			int c = stoi(v[2]);

			int pr = link[r][c].first;
			int pc = link[r][c].second;

			string str = list[pr][pc];

			for (int j = 0; j < list.size(); j++)
			{
				for (int k = 0; k < list[j].size(); k++)
				{
					if (link[j][k].first == pr && link[j][k].second == pc)
					{
						link[j][k].first = j;
						link[j][k].second = k;

						list[j][k] = "EMPTY";
					}
				}
			}

			list[r][c] = str;
		}

		else if (v[0] == "PRINT")
		{
			int r = stoi(v[1]);
			int c = stoi(v[2]);

			int pr = link[r][c].first;
			int pc = link[r][c].second;

			string str = list[pr][pc];

			answer.push_back(str);
		}
	}

    return answer;
}