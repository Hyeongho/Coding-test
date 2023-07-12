#include <string>
#include <vector>
#include <math.h>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;

	int resultA = arrayA[0];
	int resultB = arrayB[0];

	for (int i = 1; i < arrayA.size(); i++)
	{
		resultA = gcd(arrayA[i], resultA);

		if (resultA == 1)
		{
			resultA = 0;

			break;
		}
	}

	for (int i = 1; i < arrayB.size(); i++)
	{
		resultB = gcd(arrayB[i], resultB);

		if (resultB == 1)
		{
			resultB = 0;

			break;
		}
	}

	if (resultA == 0 && resultB == 0)
	{
		return 0;
	}

	if (resultA)
	{
		for (int i = 0; i < arrayB.size(); i++)
		{
			if (arrayB[i] % resultA == 0)
			{
				resultA = 0;

				break;
			}
		}
	}

	if (resultB)
	{
		for (int i = 0; i < arrayA.size(); i++)
		{
			if (arrayA[i] % resultB == 0)
			{
				resultB = 0;

				break;
			}
		}
	}

	answer = max(resultA, resultB);

    return answer;
}

int main()
{
	solution({ 10, 20 }, { 5, 17 });

	return 0;
}