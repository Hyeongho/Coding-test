#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    int start = 0;
    int idx = 0;

    while (start <= n)
    {
        if (start >= stations[idx] - w && start <= stations[idx] + w)
        {
            start = stations[idx] + w;
            idx++;
        }

        else
        {
            start += 2 * w;

            answer++;
        }

        start++;
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}