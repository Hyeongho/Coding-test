#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[510][510][4];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int change(char c, int dir)
{
	if (c == 'L')
	{
		if (dir == 0)
		{
			return 1;
		}

		else if (dir == 1)
		{
			return 2;
		}

		else if (dir == 2)
		{
			return 3;
		}

		else if (dir == 3)
		{
			return 0;
		}
	}

	else
	{
		if (dir == 0)
		{
			return 3;
		}

		else if (dir == 1)
		{
			return 0;
		}

		else if (dir == 2)
		{
			return 1;
		}

		else if (dir == 3)
		{
			return 2;
		}
	}
}

int dfs(int x, int y, int dir, int len, vector<string> &grid)
{
	if (visit[x][y][dir] == true)
	{
		return len;
	}

	visit[x][y][dir] = true;

	int nx = x;
	int ny = y;
	int ndir = dir;

	if (grid[x][y] != 'S')
	{
		ndir = change(grid[x][y], dir);
	}

	nx = x + dx[ndir];
	ny = y + dy[ndir];

	if (nx < 0)
	{
		nx = grid.size() - 1;
	}

	if (nx >= grid.size())
	{
		nx = 0;
	}

	if (ny < 0)
	{
		ny = grid[0].size() - 1;
	}

	if (ny >= grid[0].size())
	{
		ny = 0;
	}

	return dfs(nx, ny, ndir, len + 1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;

	for (int i = 0; i < grid.size(); i++)
	{
		for (int j = 0; j < grid[0].size(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int result = dfs(i, j, k, 0, grid);

				if (result != 0)
				{
					answer.push_back(result);
				}
			}
		}
	}

	sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
	solution({ "SL", "LR" });

	return 0;
}