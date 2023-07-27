#include <string>
#include <vector>
#include <math.h>

using namespace std;

int answer = 0;
int N;
vector<int> board(13, 0);

bool Check(int idx)
{
	for (int i = 0; i < idx; i++)
	{
		if (board[i] == board[idx])
		{
			return false;
		}

		else if (abs(board[i] - board[idx]) == idx - i)
		{
			return false;
		}
	}

	return true;
}

void Queen(int idx, int n)
{
	if (idx == n)
	{
		answer++;

		return;
	}

	for (int i = 0; i < n; i++)
	{
		board[idx] = i;

		if (Check(idx))
		{
			Queen(idx + 1, n);
		}

		board[idx] = 0;
	}

	return;
}

int solution(int n) {
	
	N = n;

	Queen(0, n);

    return answer;
}

int main()
{
	solution(4);

	return 0;
}