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

node *insertatbeginning(node *head, int val)
{
    return new node(val, head);
}

node *insertatend(node *head, int val)
{
    if (head == nullptr)
    {
        return new node(val, head);
    }
    node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    node *newnode = new node(val);
    temp->next = newnode;
    return head;
}

node *insertatposition(node *head, int val, int k)
{
    if (k == 0)
        return new node(val, head);

    node *temp = head;
    int cnt = 0;

    while (temp != nullptr && cnt < k - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr)
        return head;

    node *newnode = new node(val, temp->next);
    temp->next = newnode;
    return head;
}

void display(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {31, 20, 1, 90, 111};

    node *head = new node(arr[0]);
    node *temp = head;

    for (int i = 1; i < arr.size(); i++)
    {
        node *xy = new node(arr[i]);
        temp->next = xy;
        temp = xy;
    }

    display(head);

    head = insertatposition(head, 70, 3);

    display(head);
}

// copy
//  node *insertatvalue(node *head, int num, int val)
//  {
//      // If list empty
//      if (head == nullptr)
//          return head;

//     node *temp = head;

//     // Find node where data == val
//     while (temp != nullptr && temp->data != val)
//     {
//         temp = temp->next;
//     }

//     // If value not found
//     if (temp == nullptr)
//         return head;

//     // Insert after this node
//     node *newnode = new node(num, temp->next);
//     temp->next = newnode;

//     return head;
// }
