#include <string>
#include <vector>

using namespace std;

void Hanoi(vector<vector<int>>& answer, int n, int from, int by, int to)
{
    if (n == 1)
    {
        answer.push_back({ from, to });

        return;
    }

    Hanoi(answer, n - 1, from, to, by);

    answer.push_back({ from, to });

    Hanoi(answer, n - 1, by, from, to);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;

    Hanoi(answer, n, 1, 2, 3);

    return answer;
}

int main()
{
    solution(4);

    return 0;
}