#include <string>
#include <vector>

using namespace std;

vector<int> vec;
int arr[4] = { 10, 20, 30, 40 };

void dfs(vector<vector<int>>& users, vector<int>& emoticons, int& price, int& emo)
{
    if (vec.size() == emoticons.size())
    {
        int tempPrice = 0;
        int tempEmo = 0;

        for (int i = 0; i < users.size(); i++)
        {
            int p = 0;

            for (int j = 0; j < emoticons.size(); j++)
            {
                if (users[i][0] <= vec[j])
                {
                    p = p + emoticons[j] * (100 - vec[j]) / 100;
                }
            }

            if (p >= users[i][1])
            {
                tempEmo++;
            }

            else
            {
                tempPrice += p;
            }
        }

        if (tempEmo > emo)
        {
            emo = tempEmo;
            price = tempPrice;
        }

        else if (tempEmo == emo && tempPrice > price)
        {
            price = tempPrice;
        }

        return;
    }

    for (int i = 0; i < 4; i++)
    {
        vec.push_back(arr[i]);

        dfs(users, emoticons, price, emo);

        vec.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    int price = 0;
    int emo = 0;

    dfs(users, emoticons, price, emo);

    answer.push_back(emo);
    answer.push_back(price);

    return answer;
}