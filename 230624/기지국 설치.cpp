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

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}