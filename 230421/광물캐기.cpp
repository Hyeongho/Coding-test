#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int Fatigue(int cnt, int i, vector<int> mine)
{
    int pick = static_cast<int>(pow(5, 2 - i)); // �Ƿε�

    int result = 0;

    for (int i =  cnt * 5; i < (cnt + 1) * 5 && i < mine.size(); i++)
    {
        int num = mine[i] / pick;

        if (num == 0) // ��̰� �� ũ�� 0, ex) ���̾� ��̷� ö�� Ķ�� 5 / 25 �̹Ƿ� 0
        {
            result++;
        }

        else // ö ��̷� ö Ķ�� 5 / 5 = 1, ö ��̷� ���̾� Ķ�� 25 / 5 = 5
        {
            result += num;
        }
    }

    return result;
}

void dfs(int cnt, int res, vector<int> picks, vector<int> mine, int *answer)
{
    if ((!picks[0] && !picks[1] && !picks[2]) || cnt * 5 >= mine.size()) // ��̸� �� ��� �߰ų� ������ �� ĺ�� ���
    {
        *answer = min(*answer, res);
    }

    for (int i = 0; i < 3; i++)
    {
        if (picks[i])
        {
            picks[i]--;
            dfs(cnt + 1, res + Fatigue(cnt, i, mine), picks, mine, answer);
            picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = INT_MAX;

    vector<int> mine;

    for (int i = 0; i < minerals.size(); i++)
    {
        if (minerals[i] == "diamond")
        {
            mine.push_back(25);
        }

        else if (minerals[i] == "iron")
        {
            mine.push_back(5);
        }

        else
        {
            mine.push_back(1);
        }
    }

    dfs(0, 0, picks, mine, &answer);

    return answer;
}

int main()
{
    solution({ 1, 3, 2 }, { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" });

    return 0;
}