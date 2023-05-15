#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    queue<int> s;

    for (int i = 0; i < arr.size(); i++)
    {
        if (s.empty())
        {
            s.push(arr[i]);
        }

        else
        {
            int a = s.front();

            if (a != arr[i])
            {
                s.push(arr[i]);
            }
        }
    }

    while (!s.empty())
    {
        answer.push_back(s.back());

        s.pop();
    }

    // [����] ��ư�� ������ ��� ���� �� �� �ֽ��ϴ�.
    cout << "Hello Cpp" << endl;

    return answer;
}

int main()
{
    solution({ 1,1,3,3,0,1,1 });

    return 0;
}