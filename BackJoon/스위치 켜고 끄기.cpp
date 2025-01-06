#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<bool> v(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int temp;
		cin >> temp;

		v[i] = (temp != 0);
	}

	int Count;

	cin >> Count;

	for (int i = 0; i < Count; i++)
	{
		int x;
		int y;

		cin >> x >> y;

		if (x == 1)
		{
			for (int j = 1; j <= N; j++)
			{
				if (j % y == 0)
				{
					v[j] = !v[j];
				}
			}
		}

		else if (x == 2)
		{
			int left = y;
			int right = y;

			v[y] = !v[y];

			while (left > 1 && right < N && v[left - 1] == v[right + 1])
			{
				left--;
				right++;

				v[left] = !v[left];
				v[right] = !v[right];
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cout << v[i] << " ";

		if (i % 20 == 0 && i != 0)
		{
			cout << endl;
		}
	}

	return 0;
}