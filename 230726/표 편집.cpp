#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node
{
    int idx = -1;
    Node* prev = NULL;
    Node* next = NULL;
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');

    stack<Node*> s;
    vector<Node*> v;

    for (int i = 0; i <= n; i++)
    {
        v.push_back(new Node{ i });
    }

    v[0]->next = v[1];
    v[n - 1]->prev = v[n - 2];

    for (int i = 1; i < n - 1; i++)
    {
        v[i]->next = v[i + 1];
        v[i]->prev = v[i - 1];
    }

    Node* cur = v[k];

    for (int i = 0; i < cmd.size(); i++)
    {
        if (cmd[i][0] == 'U')
        {
            int a = stoi(cmd[i].substr(2));

            while (a--)
            {
                cur = cur->prev;
            }
        }

        else if (cmd[i][0] == 'D')
        {
            int a = stoi(cmd[i].substr(2));

            while (a--)
            {
                cur = cur->next;
            }
        }

        else if (cmd[i][0] == 'C')
        {
            s.push(cur);

            if (cur->prev == nullptr)
            {
                cur->next->prev = nullptr;
                cur = cur->next;
            }

            else if (cur->next == nullptr)
            {
                cur->prev->next = nullptr;
                cur = cur->prev;
            }

            else
            {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;

                cur = cur->next;
            }
        }

        else
        {
            Node* node = s.top();

            s.pop();

            if (node->prev != nullptr)
            {
                node->prev->next = node;
            }

            if (node->next != nullptr)
            {
                node->next->prev = node;
            }
        }
    }

    while (cur->prev != nullptr)
    {
        cur = cur->prev;
    }

    while (cur != nullptr)
    {
        answer[cur->idx] = 'O';

        cur = cur->next;
    }

    return answer;
}

int main()
{
    solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" });

    return 0;
}