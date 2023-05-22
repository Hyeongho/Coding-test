#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    vector<int> count(10000001, 0);

    for (int i = 0; i < tangerine.size(); i++)
    {
        count[tangerine[i]] += 1;
    }

    sort(count.begin(), count.end(), greater<int>());

    int a = 0;

    while (0 < k)
    {
        k -= count[a];
        a++;
        answer++;
    }

    return answer;
}