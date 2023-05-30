#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <map>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int time = fees[0];
    int charge = fees[1];

    int Unittime = fees[2];
    int Unitcharge = fees[3];

    unordered_map<string, string> map1;
    map<string, int> map2;

    for (int i = 0; i < records.size(); i++)
    {
        string hour = records[i].substr(0, 5);
        string num = records[i].substr(6, 4);
        string inout = records[i].substr(11);

        if (inout == "IN")
        {
            map1.insert({ num, hour });
        }

        else if (inout == "OUT")
        {
            string outtime = hour;
            string intime = map1[num];

            int elapsedMinutes = 0;

            int inhour = stoi(intime.substr(0, 2));
            int inminute = stoi(intime.substr(3, 2));

            int outhour = stoi(outtime.substr(0, 2));
            int outminute = stoi(outtime.substr(3, 2));

            elapsedMinutes = (outhour * 60 + outminute) - (inhour * 60 + inminute);

            map2[num] += elapsedMinutes;

            map1.erase(num);
        }
    }


    while (!map1.empty())
    {
        string outtime = "23:59";
        string intime = map1.begin()->second;

        string num = map1.begin()->first;

        int elapsedMinutes = 0;

        int inhour = stoi(intime.substr(0, 2));
        int inminute = stoi(intime.substr(3, 2));

        int outhour = stoi(outtime.substr(0, 2));
        int outminute = stoi(outtime.substr(3, 2));

        elapsedMinutes = (outhour * 60 + outminute) - (inhour * 60 + inminute);

        map2[num] += elapsedMinutes;

        map1.erase(num);
    }

    auto iter = map2.begin();
    auto iterEnd = map2.end();

    for (; iter != iterEnd; iter++)
    {
        if ((*iter).second <= time)
        {
            answer.push_back(charge);
        }

        else
        {
            double resulttime = ceil(((*iter).second - time) / (double)Unittime);

            int result;

            result = charge + resulttime * Unitcharge;

            answer.push_back(result);
        }
        
    }

    return answer;
}