#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    int size = balls.size();

    for (int i = 0; i < size; i++)
    {
        int len = 0;
        int a = 0;
        int b = 0;

        if (balls[i][0] == startX)
        {
            a = abs(startY - balls[i][1]);
            b = 2 * min(startX, abs(startX - m));

            if (startY > balls[i][1]) // y축 벽에 튕길 때
            {
                len = pow((a + 2 * (n - startY)), 2);
            }

            else
            {
                len = pow((a + 2 * startY), 2);
            }
        }

        else if (balls[i][1] == startY)
        {
            a = abs(startX - balls[i][0]);
            b = 2 * min(startY, abs(startY - n));

            if (startX > balls[i][0]) // x 축 벽에 튕길 때
            {
                len = pow((a + 2 * (m - startX)), 2);
            }

            else
            {
                len = pow((a + 2 * startX), 2);
            }
        }

        else
        {
            a = min(startX + balls[i][0], (m - startX) + (m - balls[i][0]));
            b = abs(startY - balls[i][1]);

            len = pow(a, 2) + pow(b, 2);

            a = abs(startX - balls[i][0]);
            b = min(startY + balls[i][1], (n - startY) + (n - balls[i][1]));
        }

        len = min(static_cast<int>((pow(a, 2) + pow(b, 2))), len);

        answer.push_back(len);
    }

    return answer;
}