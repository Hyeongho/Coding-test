#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int P;

	cin >> P;

	vector<int> v(20);

	for (int i = 0; i < P; i++)
	{
		int idx;

		cin >> idx;

		for (int j = 0; j < 20; j++)
		{
			cin >> v[j];
		}

		vector<int> line;

		int result = 0;

		for (int j = 0; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				if (v[j] > v[k])
				{
					result++;
				}
			}
		}

		cout << i + 1 << " " << result << endl;
	}

	return 0;
}

//int main()
//{
//	int P;
//
//	cin >> P;
//
//	vector<int> v(20);
//
//	for (int i = 0; i < P; i++)
//	{
//		int idx;
//
//		cin >> idx;
//
//		for (int j = 0; j < 20; j++)
//		{
//			cin >> v[j];
//		}
//
//		vector<int> line;
//
//		int result = 0;
//
//		for (int j = 0; j < v.size(); j++)
//		{
//			int pos = 0;
//
//			while (true)
//			{
//				if (pos >= line.size() || line[pos] >= v[j])
//				{
//					break;
//				}
//
//				pos++;
//			}
//
//			line.insert(line.begin() + pos, v[j]);
//
//			result += line.size() - pos - 1;
//		}
//
//		cout << i + 1 << " " << result << endl;
//	}
//
//	return 0;
//}