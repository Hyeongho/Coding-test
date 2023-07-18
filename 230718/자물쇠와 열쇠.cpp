#include <string>
#include <vector>

using namespace std;

void Rotate(vector<vector<int>>& key)
{
    vector<vector<int>> v(key.size(), vector<int>(key.size(), 0));

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            v[i][j] = key[key.size() - (j + 1)][i];
        }
    }

    key = v;
}

bool Check(vector<vector<int>>& key, vector<vector<int>>& borad, int x, int y, int sizeN)
{
    bool check = true;

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            borad[i + y][j + x] += key[i][j];
        }
    }

    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeN; j++)
        {
            if (borad[i + key.size() - 1][j + key.size() - 1] != 1)
            {
                check = false;
                break;
            }
        }
    }

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            borad[i + y][j + x] -= key[i][j];
        }
    }

    return check;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int sizeM = key.size();
    int sizeN = lock.size();

    int size = 2 * (sizeM - 1) + sizeN;

    vector<vector<int>> borad(size, vector<int>(size, 0));

    for (int i = 0; i < sizeN; i++)
    {
        for (int j = 0; j < sizeN; j++)
        {
            borad[i + sizeM - 1][j + sizeM - 1] = lock[i][j];
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <= size - sizeM; j++)
        {
            for (int k = 0; k <= size - sizeM; k++)
            {
                if (Check(key, borad, j, k, sizeN))
                {
                    return true;
                }
            }
        }

        Rotate(key);
    }

    return false;
}

int main()
{
    solution({ {0, 0, 0}, {1, 0, 0}, {0, 1, 1} }, { {1, 1, 1}, {1, 1, 0}, {1, 0, 1} });

    return 0;
}