#include <iostream>
#include <deque>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        this->data = x;
        this->left = this->right = nullptr;
    }
};

class create_binary_trees
{
public:
    void makeBinaryTree(struct Node *, int);
    void levelOrderTraversal(deque<struct Node *>);
};

void create_binary_trees::makeBinaryTree(struct Node *ptr, int data)
{
    if (data == -1)
        return;
    int d;
    ptr->data = data;
    cout << "Enter data : ";
    cin >> d;
    struct Node *node = new Node(d);

    ptr->left = node;
    makeBinaryTree(node, d);
    cout << "Enter data : ";
    cin >> d;
    node = new Node(d);

    ptr->right = node;

    makeBinaryTree(node, d);
    return;
}

void create_binary_trees::levelOrderTraversal(deque<struct Node *> dq)
{
    struct Node *ele;
    while (!dq.empty())
    {
        ele = dq.front();
        dq.pop_front();
        if(ele->data != -1)
            cout << ele->data << " ";
        if (ele->left != nullptr)
            dq.push_back(ele->left);
        if (ele->right != nullptr)
            dq.push_back(ele->right);
    }
}

int main()
{
    int r_data;
    create_binary_trees cbt;
    struct Node *root = new Node(0);
    cout << "Enter root data : ";
    cin >> r_data;
    cbt.makeBinaryTree(root, r_data);
    deque<struct Node *> dq{root};
    cbt.levelOrderTraversal(dq);

    return 0;
}