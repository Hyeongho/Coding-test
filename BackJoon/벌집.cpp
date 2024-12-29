#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int room = 1;
	int layer = 1;

	while (N > room)
	{
		room += 6 * layer;
		layer++;
	}

	cout << layer << endl;

	return 0;
}