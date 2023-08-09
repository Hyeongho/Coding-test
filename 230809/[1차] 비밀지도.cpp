#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		string str = "";

		int num = arr1[i] | arr2[i];

		while (str.size() != n)
		{
			if (num % 2 == 0)
			{
				str += " ";
			}

			else
			{
				str += "#";
			}

			num /= 2;
		}

		reverse(str.begin(), str.end());

		answer.push_back(str);
	}

    return answer;
}

int main()
{
	solution(6, { 46, 33, 33 ,22, 31, 50 }, { 27 ,56, 19, 14, 14, 10 });

	return 0;
}