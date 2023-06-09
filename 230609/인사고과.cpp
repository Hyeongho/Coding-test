#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b)
{
    if (get<0>(a) == get<0>(b))
    {
        return get<1>(a) < get<1>(b);
    }

    return get<0>(a) > get<0>(b);
}

bool cmp1(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

int solution(vector<vector<int>> scores) {
    int answer = 1;

    auto a = scores[0];

    vector<pair<int, int>> v;

    vector<tuple<int, int, int>> v1;

    for (int i = 0; i < scores.size(); i++)
    {
        v1.push_back({ scores[i][0], scores[i][1], i });
    }

    sort(v1.begin(), v1.end(), cmp);

    for (int i = 0; i < scores.size(); i++)
    {
        bool flag = true;

        for (int j = 0; j < i; j++)
        {
            if ((get<0>(v1[i]) < get<0>(v1[j])) && (get<1>(v1[i]) < get<1>(v1[j])))
            {
                flag = false;

                break;
            }
        }

        if (flag)
        {
            v.push_back({ get<0>(v1[i]) + get<1>(v1[i]), get<2>(v1[i]) });
        }
    }

    sort(v.begin(), v.end(), cmp1);

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second == 0)
        {
            return i + 1;
        }
    }

    return -1;
}