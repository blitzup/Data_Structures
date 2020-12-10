#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int data, struct node *next)
    {
        this->data = data;
        this->next = next;
    }
};

struct linked_list
{
    node *head;
    linked_list() : head(nullptr) {}
    void add_back(int data);
    void display();
};

void linked_list::add_back(int data)
{
    struct node *p = new node(data, nullptr);
    if (head == nullptr)
        head = p;
    else
    {
        struct node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = p;
    }
}

void linked_list::display()
{
    if (head == nullptr)
        cout << "Nothing to display." << endl;
    else
    {
        struct node *temp = head;
        while (temp != nullptr)
            cout << temp->data << " ", temp = temp->next;
        cout << endl;
    }
}

int main()
{
    struct linked_list *ll = new linked_list();
    ll->add_back(7);
    ll->add_back(10);
    ll->add_back(18);

    ll->display();

    return 0;
}