#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    vector<string> v1 = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    vector<int> v2 = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int day = 0;

    for (int i = 0; i < a - 1; i++)
    {
        day += v2[i];
    }

    day += b;

    int idx = day % 7;

    return v1[idx];
}