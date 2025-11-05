#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
int searchInLinkedList(node *head, int k)
{
    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);

    cout << searchInLinkedList(head, 21);
}

// copy addon's
//  if (searchInLinkedList(head, 20) == 1)
//      cout << "Found\n";
//  else
//      cout << "Not Found\n";
