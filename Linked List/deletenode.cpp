#include <iostream>
#include <vector>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int data1, node *next1 = nullptr)
    {
        data = data1;
        next = next1;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *deletehead(node *head)
{
    if (head == nullptr)
        return nullptr;

    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

node *deletelast(node *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
        return nullptr;
    node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    node *lastnode = temp->next; // last node
    temp->next = nullptr;        // unlink last node
    delete lastnode;             // free memory
    return head;
}

node *removek(node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    if (k == 1)
    {
        node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    node *temp = head;
    node *prev = nullptr;
    while (temp->next != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 8, 7};

    node *head = new node(arr[0]);
    node *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *newNode = new node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }

    display(head);

    // head = deletelast(head);

    head = removek(head, 2);
    display(head);
}

node *removedata(node *head, int data)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    node *temp = head;
    node *prev = nullptr;
    while (temp->next != nullptr)
    {
        if (temp->data == data)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}