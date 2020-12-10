#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct node *reverse(struct node *head, int k)
{
    struct node *temp = head;
    struct node *first = nullptr, *second = nullptr, *mainhead = nullptr;
    struct node *start = head, *nextstart = nullptr, *last = nullptr;
    int forloops = 0, flag = 0;

    while (temp != nullptr)
    {
        second = nullptr;
        first = nullptr;
        for (auto i = 0; i < k; i++)
        {
            // if(i == 0 && flag == 0) start = temp;
            second = temp;
            temp = temp->next;
            second->next = first;
            first = second;
            if (temp == nullptr)
                break;
        }

        if (flag == 0)
        {
            last = second;
            nextstart = temp;
            flag = 1;
            mainhead = second;
        }

        forloops++;
        if (forloops == 2)
        {
            start->next = second;
            start = nextstart;
            nextstart = temp;
            last = second;
            forloops = 1;
        }
    }

    return mainhead;
}

void printlist(struct node *head)
{
    struct node *temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        struct node *temp = nullptr;
        struct node *head = nullptr;

        for (auto i = 0; i < n; i++)
        {
            int value;
            cin >> value;

            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }

            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;
        head = reverse(head, k);
        printlist(head);

        return 0;
    }
    return 0;
}