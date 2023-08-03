#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[106][106][2];
int N;

bool Add(int x, int y, int a)
{
	if (a == 0)
	{
		if (y == 0)
		{
			return true;
		}

		if (x > 0 && arr[x - 1][y][1])
		{
			return true;
		}

		if (y < N && arr[x][y][1])
		{
			return true;
		}

		if (y > 0 && arr[x][y - 1][0])
		{
			return true;
		}
	}

	else
	{
		if (y > 0 && arr[x][y - 1][0])
		{
			return true;
		}

		if (x < N && y > 0 && arr[x + 1][y - 1][0])
		{
			return true;
		}

		if (x > 0 && x < N && arr[x - 1][y][1] && arr[x + 1][y][1])
		{
			return true;
		}
	}

	return false;
}

bool Delete(int x, int y, int a)
{
	arr[x][y][a] = 0;

	if (a == 0)
	{
		if (y < N && arr[x][y + 1][0] && !Add(x, y + 1, 0))
		{
			return false;
		}

		if (y < N && arr[x][y + 1][1] && !Add(x, y + 1, 1))
		{
			return false;
		}

		if (x > 0 && y < N && arr[x - 1][y + 1][1] && !Add(x - 1, y + 1, 1))
		{
			return false;
		}
	}

	else
	{
		if (arr[x][y][0] && !Add(x, y, 0))
		{
			return false;
		}

		if (x < N && arr[x + 1][y][0] && !Add(x + 1, y, 0))
		{
			return false;
		}

		if (x > 0 && arr[x - 1][y][1] && !Add(x - 1, y, 1)) 
		{
			return false;
		}

		if (x < N && arr[x + 1][y][1] && !Add(x + 1, y, 1)) 
		{
			return false;
		}
	}

	return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

	N = n;

	for (int i = 0; i < build_frame.size(); i++)
	{
		int x = build_frame[i][0];
		int y = build_frame[i][1];

		int a = build_frame[i][2];
		int b = build_frame[i][3];

		if (b == 0)
		{
			if (!Delete(x, y, a))
			{
				arr[x][y][a] = 1;
			}
		}

		else
		{
			if (Add(x, y, a))
			{
				arr[x][y][a] = 1;
			}
		}
	}

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (arr[i][j][0])
			{
				answer.push_back({ i, j, 0 });
			}

			if (arr[i][j][1])
			{
				answer.push_back({ i, j, 1 });
			}
		}
	}

    return answer;
}