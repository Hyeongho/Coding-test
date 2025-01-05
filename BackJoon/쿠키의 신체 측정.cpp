#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;

	cin >> N;

	vector<string> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	int HeartX = -1;
	int HeartY = -1;

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (v[i][j] == '*' && v[i - 1][j] == '*' && v[i][j - 1] == '*' && v[i][j + 1] == '*' && v[i + 1][j] == '*')
			{
				HeartX = i + 1;
				HeartY = j + 1;

				break;
			}
		}

		if (HeartX != -1)
		{
			break;
		}
	}

	int LeftArm = 0;

	for (int i = HeartY - 2; i >= 0; i--)
	{
		if (v[HeartX - 1][i] == '*')
		{
			LeftArm++;
		}

		else
		{
			break;
		}
	}

	int RightArm = 0;

	for (int i = HeartY; i < N ; i++)
	{
		if (v[HeartX - 1][i] == '*')
		{
			RightArm++;
		}

		else
		{
			break;
		}
	}

	int waist = 0;

	for (int i = HeartX; i < N; i++)
	{
		if (v[i][HeartY - 1] == '*')
		{
			waist++;
		}

		else
		{
			break;
		}
	}

	int LeftLeg = 0;
	int RightLeg = 0;

	for (int i = HeartX + waist; i < N; i++)
	{
		if (HeartY > 1 && v[i][HeartY - 2] == '*')
		{
			LeftLeg++;
		}

		if (HeartY < N && v[i][HeartY] == '*')
		{
			RightLeg++;
		}
	}

	cout << HeartX << " " << HeartY << endl;
	cout << LeftArm << " " << RightArm << " " << waist << " " << LeftLeg << " " << RightLeg << endl;

	return 0;
}