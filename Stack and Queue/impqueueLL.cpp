#include <iostream>
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

class Queue
{
public:
    node *start, *end;
    int size;

    Queue()
    {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int val)
    {
        node *temp = new node(val);
        if (start == nullptr)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
        size++;
        cout << val << " pushed to queue\n";
    }

    void pop()
    {
        if (start == nullptr)
        {
            cout << "Queue underflow\n";
            return;
        }
        node *temp = start;
        cout << temp->data << " popped from queue\n";
        start = start->next;
        if (start == nullptr)
        {
            end = nullptr;
        }
        delete temp;
        size--;
    }

    void front()
    {
        if (start == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << start->data << endl;
    }

    void display()
    {
        if (start == nullptr)
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        node *temp = start;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void sizeq()
    {
        cout << "Queue size: " << size << endl;
    }
};

int main()
{
    // gpt
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    q.display();
    q.front();
    q.sizeq();

    q.pop();
    q.display();
    q.front();
    q.sizeq();

    q.pop();
    q.pop();
    q.pop();

    return 0;
}

// copy
//  class QueueNode
//  {
//  public:
//      int val;
//      QueueNode *next;
//      QueueNode(int data)
//      {
//          val = data;
//          next = nullptr;
//      }
//  };
//  QueueNode *Front = nullptr, *Rare = nullptr;

// class Queue
// {
// public:
//     int size = 0;
//     bool Empty();
//     void Enqueue(int value);
//     void Dequeue();
//     int Peek();
// };
// bool Queue ::Empty()
// {
//     return Front == nullptr;
// }
// int Queue ::Peek()
// {
//     if (Empty())
//     {
//         cout << "Queue is Empty" << endl;
//         return -1;
//     }
//     else
//         return Front->val;
// }
// void Queue ::Enqueue(int value)
// {
//     QueueNode *Temp;
//     Temp = new QueueNode(value);
//     if (Temp == nullptr) // When heap exhausted
//         cout << "Queue is Full" << endl;
//     else
//     {
//         if (Front == nullptr)
//         {
//             Front = Temp;
//             Rare = Temp;
//         }
//         else
//         {
//             Rare->next = Temp;
//             Rare = Temp;
//         }
//         cout << value << " Inserted into Queue " << endl;
//         size++;
//     }
// }
// void Queue ::Dequeue()
// {
//     if (Front == nullptr)
//         cout << "Queue is Empty" << endl;
//     else
//     {
//         cout << Front->val << " Removed From Queue" << endl;
//         QueueNode *Temp = Front;
//         Front = Front->next;
//         delete Temp;
//         size--;
//     }
// }