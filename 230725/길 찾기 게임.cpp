#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int idx;

    int x; 
    int y;

    Node* Left;
    Node* Right;
};

bool compare(Node a, Node b)
{
    if (a.y == b.y)
    {
        return a.x < b.x;
    }

    return a.y > b.y;
}

void SetTree(Node* Root, Node* Child)
{
    if (Root->x > Child->x)
    {
        if (Root->Left == NULL)
        {
            Root->Left = Child;

            return;
        }

        SetTree(Root->Left, Child);
    }

    else
    {
        if (Root->Right == NULL)
        {
            Root->Right = Child;

            return;
        }

        SetTree(Root->Right, Child);
    }
}

void PreOrder(vector<int>& Pre, Node* Tree)
{
    if (Tree == NULL)
    {
        return;
    }

    Pre.push_back(Tree->idx);

    PreOrder(Pre, Tree->Left);
    PreOrder(Pre, Tree->Right);
}

void PostOrder(vector<int>& Post, Node* Tree)
{
    if (Tree == NULL)
    {
        return;
    }

    PostOrder(Post, Tree->Left);
    PostOrder(Post, Tree->Right);

    Post.push_back(Tree->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    vector<Node> Tree;

    for (int i = 0; i < nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];

        Tree.push_back({ i + 1, x, y, NULL, NULL });
    }

    sort(Tree.begin(), Tree.end(), compare);

    Node* Root = &Tree[0];

    for (int i = 1; i < Tree.size(); i++)
    {
        SetTree(Root, &Tree[i]);
    }

    vector<int> pre;
    vector<int> post;

    PreOrder(pre, Root);
    PostOrder(post, Root);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}