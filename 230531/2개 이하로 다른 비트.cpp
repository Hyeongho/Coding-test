#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] % 2 == 0)
		{
			answer.push_back(numbers[i]++);
		}

		else
		{
			long long bit = 1;

			while (true)
			{
				if ((numbers[i] & bit) == 0)
				{
					break;
				}

				bit *= 2;
			}

			bit /= 2;

			answer.push_back(numbers[i] + bit);
		}
	}

    return answer;
}

int main()
{
	solution({ 2, 11 });

	return 0;
}