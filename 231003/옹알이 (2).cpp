#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> word = { "aya", "ye", "woo", "ma" };

    for (int i = 0; i < babbling.size(); i++)
    {
        string str = babbling[i];

        string str1;

        bool enable = true;

        vector<bool> visit(4, false);
            
        for (int j = 0; j < babbling[i].size();)
        {
            if (str.substr(j, 3) == "aya" && str1 != "aya")
            {
                j += 3;

                str1 = "aya";
            }

            else if (str.substr(j, 2) == "ye" && str1 != "ye")
            {
                j += 2;

                str1 = "ye";
            }

            else if (str.substr(j, 3) == "woo" && str1 != "woo")
            {
                j += 3;

                str1 = "woo";
            }

            else if (str.substr(j, 2) == "ma" && str1 != "ma")
            {
                j += 2;

                str1 = "ma";
            }

            else
            {
                enable = false;

                break;
            }
        }

        if (enable)
        {
            answer++;
        }
    }

    return answer;
}

int main()
{
    solution({ "yayae" });

    return 0;
}