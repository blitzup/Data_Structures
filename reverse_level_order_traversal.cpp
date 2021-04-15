#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> reverse_level;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *ele = q.front();
        reverse_level.push_back(ele->data);

        if (ele->right != nullptr)
            q.push(ele->right);

        if (ele->left != nullptr)
            q.push(ele->left);

        q.pop();
    }
    reverse(reverse_level.begin(), reverse_level.end());
    return reverse_level;
}

void construct_tree(Node *root)
{
    int data;
    cin >> data;

    if(data != -1)
    {
        Node *p = new Node();
        p->data = data;
        p->left = nullptr;
        p->right = nullptr;
        root->left = p;
        construct_tree(p);
    }

    cin >> data;
    if(data != -1)
    {
        Node *p = new Node();
        p->data = data;
        p->left = nullptr;
        p->right = nullptr;
        root->right = p;
        construct_tree(p);
    }  
}

void preorder(Node * root)
{
    if(root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node *p = new Node();
    int data;
    cin >> data;
    p->data = data;
    p->left = nullptr;
    p->right = nullptr;

    construct_tree(p);
    preorder(p);
    vector<int> levelOrderVec = reverseLevelOrder(p);

    cout << endl;
    for(auto const & ele : levelOrderVec)
        cout << ele << " ";

    return 0;

}