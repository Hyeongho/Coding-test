#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;

	vector<bool> v(cards.size() + 1, false);

	priority_queue<int> pq;

	for (int i = 0; i < cards.size(); i++)
	{
		int idx = cards[i];
		int cnt = 0;

		while (1)
		{
			if (v[idx])
			{
				if (cnt)
				{
					pq.push(cnt);
				}

				break;
			}

			cnt++;
			v[idx] = true;
			idx = cards[idx - 1];
		}
	}

	if (pq.size() <= 1)
	{
		answer = 0;
	}

	else
	{
		int a = pq.top();
		pq.pop();

		int b = pq.top();

		answer = a * b;
	}

    return answer;
}

int main()
{
	solution({ 8, 6, 3, 7, 2, 5, 1, 4 });

	return 0;
}