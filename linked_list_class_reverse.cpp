#include <iostream>
using namespace std;

class Node
{
public:
    Node(int data, Node *next)
    {
        this->data = data, this->next = next;
    }

    int data;
    Node *next;
};

class LinkedList
{
public:
    LinkedList() : head(nullptr)
    {
    }

    void add_back(int data);
    void add_front(int data);
    void add_index(int data, int index);

    void delete_back();
    void delete_front();
    void delete_index(int index);

    void reverse_gfg();
    void reverse();
    void reverse_recurssive(Node *, Node *, Node *);

    void display();

// private:
    Node *head;
};

void LinkedList::add_front(int data)
{
    Node *p = new Node(data, nullptr);
    if (head == nullptr)
        head = p;
    else
    {
        p->next = head;
        head = p;
    }
}

void LinkedList::add_back(int data)
{
    Node *p = new Node(data, nullptr);
    if (head == nullptr)
        head = p;
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = p;
    }
}

void LinkedList::display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void LinkedList::reverse()
{
    if (head->next != nullptr)
    {
        Node *temp = head->next->next;
        Node *first = head;
        Node *second = head->next;
        first->next = nullptr;
        while (temp != nullptr)
        {
            second->next = first;
            first = second;
            second = temp;
            temp = temp->next;
        }
        second->next = first;
        head = second;
    }
}

void LinkedList::reverse_gfg()
{
    Node *temp = head;
    Node *first = nullptr, *second = nullptr;

    while (temp != nullptr)
    {
        second = temp;
        temp = temp->next;
        second->next = first;
        first = second;
    }
    head = second;
}

void LinkedList::reverse_recurssive(Node *temp, Node *first, Node *second)
{
    if (temp == nullptr)
        head = second;
    else
    {
        second = temp;
        temp = temp->next;
        second->next = first;
        first = second;
        reverse_recurssive(temp, first, second);
    }
}

int main()
{

    //new keyword is used to instantiate an object and space is allocated in heap memory
    //using this we get a pointer to the new object created
    LinkedList *linked_list = new LinkedList();
    linked_list->add_front(9);
    linked_list->add_front(6);
    linked_list->add_back(69);
    linked_list->display();
    cout << endl;
    // cout << linked_list->head->data;
    linked_list->reverse_recurssive(linked_list->head, nullptr, nullptr);
    linked_list->display();

    delete linked_list;

    //when object is created without using new then space is allocated in stack memory
    //object destroyed whenever the scope ends

    // LinkedList linked_list2;
    // linked_list2.add_front(99);
    // linked_list2.display();

    return 0;
}