#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long find(long long num)
{
	if (num == 1)
	{
		return 0;
	}

	int result = 1;

	for (int j = 2; j * j <= num; j++)
	{
		if (num % j == 0)
		{
			result = j;

			if (num / j <= 10000000)
			{
				return num / j;

				break;
			}
		}
	}

	return result;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;

	for (long long i = begin; i <= end; i++)
	{
		answer.push_back(find(i));
	}

    return answer;
}