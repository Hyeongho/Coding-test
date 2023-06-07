#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>

using namespace std;

int Time(string& str, bool End)
{
    int a;
    int b;

    if (End)
    {
        a = stoi(str.substr(0, 2));
        b = stoi(str.substr(3, 2)) + 10;
    }

    else
    {
        a = stoi(str.substr(0, 2));
        b = stoi(str.substr(3, 2));
    }

    if (b >= 60)
    {
        a++;

        b -= 60;
    }

    return (a * 60 )+ b;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<pair<int, int>> v;
    vector<pair<int, int>> v1;

    for (int i = 0; i < book_time.size(); i++)
    {
        v.push_back({ Time(book_time[i][0], false), Time(book_time[i][1], true) });
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        int a = v[i].first;

        vector<pair<int, int>> temp;

        for (int j = 0; j < v1.size(); j++)
        {
            if (a < v1[j].second)
            {
                temp.push_back(v1[j]);
            }
        }

        v1 = temp;
        v1.push_back(v[i]);
        answer = max(answer, (int)v1.size());
    }

    return answer;
}

int main()
{
    solution({ {"15:00", "17:00"}, {"16:40", "18:20"}, {"14:20", "15:20"}, {"14:10", "19:20"}, {"18:20", "21:20"} });

    return 0;
}