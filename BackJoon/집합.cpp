#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    int bit = 0;

    for (int i = 0; i < M; i++)
    {
        string str;
        int a;

        cin >> str;

        if (str == "add")
        {
            cin >> a;
            bit |= (1 << (a - 1));
        }

        else if (str == "remove")
        {
            cin >> a;
            bit &= ~(1 << (a - 1));
        }

        else if (str == "check")
        {
            cin >> a;

            if (bit & (1 << (a - 1)))
            {
                cout << 1 << '\n';
            }

            else
            {
                cout << 0 << '\n';
            }
        }

        else if (str == "toggle")
        {
            cin >> a;
            bit ^= (1 << (a - 1));
        }

        else if (str == "all")
        {
            bit = (1 << 20) - 1;
        }

        else if (str == "empty")
        {
            bit = 0;
        }
    }

    return 0;
}