#include <iostream>
using namespace std;

class impqueuearray
{
    int st[10];
    int front, rear, x;

public:
    impqueuearray()
    {
        front = -1;
        rear = -1;
        x = sizeof(st) / sizeof(st[0]);
    }

    void enqueue(int val)
    {
        if (rear == x - 1)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        st[rear] = val;
        cout << val << " enqueued!" << endl;
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << st[front] << " dequeued!" << endl;
        front++;
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << st[i] << " ";
        cout << endl;
    }

    void sizei()
    {
        if (front == -1)
            cout << "Size: 0" << endl;
        else
            cout << "Size: " << (rear - front + 1) << endl;
    }

    void peak()
    {
        cout << "Peak element : " << st[rear] << endl;
    }
};

int main()
{
    impqueuearray q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.peak();
    q.display();
    q.dequeue();
    q.display();
    q.sizei();
}

// copy
// class Queue
// {
//     int *arr;
//     int start, end, currSize, maxSize;
// public:
//     Queue()
//     {
//         arr = new int[16];
//         start = -1;
//         end = -1;
//         currSize = 0;
//     }

//     Queue(int maxSize)
//     {
//         (*this).maxSize = maxSize;
//         arr = new int[maxSize];
//         start = -1;
//         end = -1;
//         currSize = 0;
//     }
//     void push(int newElement)
//     {
//         if (currSize == maxSize)
//         {
//             cout << "Queue is full\nExiting..." << endl;
//             exit(1);
//         }
//         if (end == -1)
//         {
//             start = 0;
//             end = 0;
//         }
//         else
//             end = (end + 1) % maxSize;
//         arr[end] = newElement;
//         cout << "The element pushed is " << newElement << endl;
//         currSize++;
//     }
//     int pop()
//     {
//         if (start == -1)
//         {
//             cout << "Queue Empty\nExiting..." << endl;
//         }
//         int popped = arr[start];
//         if (currSize == 1)
//         {
//             start = -1;
//             end = -1;
//         }
//         else
//             start = (start + 1) % maxSize;
//         currSize--;
//         return popped;
//     }
//     int top()
//     {
//         if (start == -1)
//         {
//             cout << "Queue is Empty" << endl;
//             exit(1);
//         }
//         return arr[start];
//     }
//     int size()
//     {
//         return currSize;
//     }
// };