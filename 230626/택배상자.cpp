#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    vector<int> v;
    stack<int> s;

    for (int i = 0; i < order.size(); i++)
    {
        v.push_back(i + 1);
    }

    for (int i = 0; i < order.size(); i++)
    {
        if (v[i] != order[answer])
        {
            s.push(v[i]);
        }

        else if (v[i] == order[answer])
        {
            answer++;
        }

        else if (!s.empty() && s.top() == v[i])
        {
            answer++;
            s.pop();
        }

        while (!s.empty() && s.top() == order[answer])
        {
            answer++;
            s.pop();
        }
    }

    return answer;
}

int main()
{
    solution({ 4, 3, 1, 2, 5 });

    return 0;
}