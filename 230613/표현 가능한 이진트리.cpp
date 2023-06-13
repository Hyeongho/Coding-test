#include <string>
#include <vector>

using namespace std;

string Ret(long long number)
{
	string ret = "";

	while (number > 0)
	{
		ret = to_string(number % 2) + ret;

		number /= 2;
	}

	return ret;
}

string FullTree(string str)
{
	int idx = 2;

	string ret = str;

	while (true)
	{
		if (str.size() <= idx - 1)
		{
			break;
		}

		idx *= 2;
	}

	for (int i = 0; i < idx - 1 - str.size(); i++)
	{
		ret = "0" + ret;
	}

	return ret;
}

bool IsAllZero(string str)
{
	bool isZero = true;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != '0')
		{
			return false;
		}
	}

	return true;
}

bool IsMakeTree(string str)
{
	if (str.size() == 1 || IsAllZero(str))
	{
		return true;
	}

	int mid = str.size() / 2;

	string Left = str.substr(0, mid);
	string Right = str.substr(mid + 1);

	if (str[mid] == '1' && IsMakeTree(Left) && IsMakeTree(Right))
	{
		return true;
	}

	else
	{
		return false;
	}
}

vector<int> solution(vector<long long> numbers) {
	vector<int> answer;

	for (int i = 0; i < numbers.size(); i++)
	{
		string ret = "";
		string tree = "";

		ret = Ret(numbers[i]);
		tree = FullTree(ret);

		answer.push_back(IsMakeTree(tree));
	}

	return answer;
}

int main()
{
	solution({ 7, 42, 5 });

	return 0;
}