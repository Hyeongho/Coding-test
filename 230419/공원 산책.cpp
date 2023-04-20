#include <string>
#include <vector>

using namespace std;

void Start(int* x, int* y, vector<string> park)
{
    for (int i = 0; i < park.size(); i++)
    {
        for (int j = 0; j < park[i].size(); j++)
        {
            if (park[i][j] == 'S')
            {
                *x = j;
                *y = i;

                return;;
            }
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    int x = 0;
    int y = 0;

    Start(&x, &y, park);

    for (int i = 0; i < routes.size(); i++)
    {
        char dir = routes[i][0];
        int n = routes[i][2] - '0';

        int disX = 0;
        int disY = 0;

        switch (dir)
        {
        case 'W':      
            disX = -1;

            break;

        case 'S':          
            disY = 1;

            break;

        case 'E':
            disX = 1;

            break;

        case 'N':
            disY = -1;

            break;

        default:
            break;
        }     

        if ((x + (n * disX) < park[0].size() && x + (n * disX) >= 0) && (y + (n * disY) < park.size() && y + (n * disY) >= 0))
        {
            int j = 1;

            for (j = 1; j <= n; j++)
            {
                if (park[y + (j * disY)][x + (j * disX)] == 'X')
                {
                    break;
                }
            }

            if (j > n)
            {
                x += n * disX;
                y += n * disY;
            }
        }
    }

    answer.push_back(y);
    answer.push_back(x);

    return answer;
}

int main()
{
    solution({ "OSO","OOO","OXO","OOO" }, { "E 2","S 3","W 1" });

    return 0;
}