#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool comepare(vector<int> &a, vector<int> &b)
{
	if (a[1] > b[1])
	{
		return true;
	}

	return false;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

	sort(dungeons.begin(), dungeons.end(), comepare);

	do
	{
		auto iter = dungeons.begin();
		auto iterEnd = dungeons.end();

		int cnt = 0;
		int curK = k;

		for ( ; iter != iterEnd; iter++)
		{
			if (curK >= (*iter)[1])
			{
				cnt++;
				curK -= (*iter)[0];
			}
		}

		answer = max(cnt, answer);

	} while (next_permutation(dungeons.begin(), dungeons.end(), comepare));

    return answer;
}

int main()
{
	solution(80, { {80, 20}, {50, 40}, {30, 10} });

	return 0;
}