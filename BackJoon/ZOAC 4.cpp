#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	double H;
	double W;
	double N;
	double M;

	cin >> H >> W >> N >> M;

	cout << ceil(H / (N + 1)) * ceil(W / (M + 1));

	return 0;
}