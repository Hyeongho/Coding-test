#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";

    vector<int> v;

    for (int i = 0; i < timetable.size(); i++)
    {
        int time = stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 2));

        v.push_back(time);
    }

    sort(v.begin(), v.end());

    int idx = 0;
    int BusTime = 540;

    int time;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = idx; j < v.size(); j++)
        {
            if (v[j] <= BusTime)
            {
                idx++;
                count++;

                if (count == m)
                {
                    break;
                }
            }
        }

        if (i == n - 1)
        {
            if (count == m)
            {
                time = v[idx - 1] - 1;
            }

            else
            {
                time = BusTime;
            }
        }

        BusTime += t;
    }

    int hour = time / 60;
    int min = time % 60;

    if (hour < 10)
    {
        answer = "0" + to_string(hour) + ":";
    }

    else
    {
        answer = to_string(hour) + ":";
    }

    if (min < 10)
    {
        answer += "0" + to_string(min);
    }

    else
    {
        answer += to_string(min);
    }

    return answer;
}

int main()
{
    solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });

    return 0;
}