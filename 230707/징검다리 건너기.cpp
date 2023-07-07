#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool IsStones(vector<int>& stones, int mid, int k)
{
    int count = 0;

    for (int i = 0; i < stones.size(); i++)
    {
        if (stones[i] - mid <= 0)
        {
            count++;
        }

        else
        {
            count = 0;
        }

        if (count >= k)
        {
            return true;
        }
    }

    return false;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = *min_element(stones.begin(), stones.end());
    int right = *max_element(stones.begin(), stones.end());

    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (IsStones(stones, mid, k))
        {
            right = mid - 1;
        }

        else
        {
            left = mid + 1;
        }
    }

    return left;
}