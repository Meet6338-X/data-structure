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

    cout << temp << '\n';
    temp = head;
    while (temp)
    {
        cout << temp->data << '\n';
        temp = temp->next;
    }
}