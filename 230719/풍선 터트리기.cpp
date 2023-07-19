#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;

    int leftmin = a[0];
    int rightmin = a[a.size() - 1];

    vector<int> left(a.size());
    vector<int> right(a.size());

    for (int i = 0; i < a.size(); i++)
    {
        if (leftmin > a[i])
        {
            leftmin = a[i];
        }

        left[i] = leftmin;
    }

    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (rightmin > a[i])
        {
            rightmin = a[i];
        }

        right[i] = rightmin;
    }


    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= left[i] || a[i] <= right[i])
        {
            answer++;
        }
    }

    return answer;

}

int main()
{
    solution({ -16,27,65,-2,58,-92,-71,-68,-61,-33 });

    return 0;
}