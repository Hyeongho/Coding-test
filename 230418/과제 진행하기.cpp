#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(tuple<string, int, int> a, tuple<string, int, int> b)
{
    return get<1>(a) < get<1>(b);
}

int after_study(int start, int time)
{
    int start_h = start / 100, start_m = start % 100;
    int time_h = time / 60, time_m = time % 60;

    return ((start_h + time_h + (start_m + time_m) / 60) * 100 + (start_m + time_m) % 60);
}

int rest_time(tuple<string, int, int> cur, tuple<string, int, int> start, int time)
{
    int h, m;

    h = get<1>(start) / 100 - time / 100;
    m = get<1>(start) % 100 - time % 100;

    time = h * 60 + m;

    return (get<2>(cur) - time);
}


vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;

    int n = plans.size();

    deque<tuple<string, int, int>> List;
    stack<tuple<string, int, int>> Wait;

    for (int i = 0; i < n; i++)
    {
        List.push_back({ plans[i][0], stoi(plans[i][1]) * 100 + stoi(plans[i][1].substr(3,2)), stoi(plans[i][2]) });
    }

    sort(List.begin(), List.end(), compare);

    int time = get<1>(List.front());

    while (!Wait.empty() || !List.empty())
    {
        tuple<string, int, int> cur;

        if (!Wait.empty() && (List.empty() || time < get<1>(List.front())))
        {
            cur = Wait.top();
            Wait.pop();
        }

        else
        {
            cur = List.front();
            List.pop_front();

            time = get<1>(cur);
        }

        if (!List.empty() && after_study(time, get<2>(cur)) > get<1>(List.front()))
        {
            get<2>(cur) = rest_time(cur, List.front(), time);
            Wait.push(cur);
            time = get<1>(List.front());
        }

        else
        {
            answer.push_back(get<0>(cur));
            time = after_study(time, get<2>(cur));
        }
    }

    return answer;
}

int main()
{
    solution({ {"korean", "11:40", "30"}, {"english", "12:10", "20"}, {"math", "12:30", "40"} });

    return 0;
}