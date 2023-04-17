#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);

    queue<pair<int, int>> q;

    int sum = 0;
    int len = sequence.size();

    for (int i = 0; i < sequence.size(); i++)
    {
        q.push(make_pair(sequence[i], i));
        sum += sequence[i];

        while (sum > k)
        {
            sum -= q.front().first;
            q.pop();
        }

        if (sum == k && q.size() < len)
        {
            len = q.size();
            answer[0] = q.front().second;
            answer[1] = q.back().second;
        }
    }

    return answer;
}

int main()
{
    solution({ 1, 2, 3, 4, 5 }, 7);

    return 0;
}