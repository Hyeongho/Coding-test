#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
	long long answer = 0;

	unordered_map<long long, long long> m;

	for (int i = 0; i < weights.size(); i++)
	{
		m[weights[i]]++;
	}

	for (int i = 0; i < weights.size(); i++)
	{
		if (weights[i] % 2 == 0)
		{
			long long a = (long long)(weights[i] / 2) * 3;

			if (a <= 1000)
			{
				answer += m[a];
			}
		}

		if (weights[i] % 3 == 0)
		{
			long long a = (long long)(weights[i] / 3) * 4;

			if (a <= 1000)
			{
				answer += m[a];
			}
		}

		long long a = (long long)weights[i] * 2;

		if (a <= 1000)
		{
			answer += m[a];
		}
	}

	auto iter = m.begin();
	auto iterEnd = m.end();

	for (; iter != iterEnd; iter++)
	{
		if (iter->second >= 2)
		{
			answer += (iter->second * (iter->second - 1)) / 2;
		}
	}

	return answer;
}