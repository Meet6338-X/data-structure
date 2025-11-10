#include <iostream>
using namespace std;

class Stack
{
    int top;
    int arr[20];
    int n;

public:
    Stack()
    {
        top = -1;
        n = 20;
    }

    void push(int val)
    {
        if (top == n - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }
};

class Queue
{
    Stack s1, s2;

public:
    void enqueue(int val)
    {
        // Move all elements from s1 to s2
        while (!s1.isEmpty())
        {
            s2.push(s1.peek());
            s1.pop();
        }

        // Push new element into s1
        s1.push(val);

        // Move everything back to s1
        while (!s2.isEmpty())
        {
            s1.push(s2.peek());
            s2.pop();
        }

        cout << val << " enqueued\n";
    }

    void dequeue()
    {
        if (s1.isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }
        cout << s1.peek() << " dequeued\n";
        s1.pop();
    }

    void front()
    {
        if (s1.isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << s1.peek() << endl;
    }

    void size()
    {
        cout << "Queue size: " << s1.size() << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.front();
    q.size();

    q.dequeue();
    q.front();
    q.size();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}

// copy
//  #include <bits/stdc++.h>

// using namespace std;

// struct Queue
// {
//     stack<int> input, output;

//     // Push elements in queue
//     void Push(int data)
//     {
//         // Pop out all elements from the stack input
//         while (!input.empty())
//         {
//             output.push(input.top());
//             input.pop();
//         }
//         // Insert the desired element in the stack input
//         cout << "The element pushed is " << data << endl;
//         input.push(data);
//         // Pop out elements from the stack output and push them into the stack input
//         while (!output.empty())
//         {
//             input.push(output.top());
//             output.pop();
//         }
//     }
//     // Pop the element from the Queue
//     int Pop()
//     {
//         if (input.empty())
//         {
//             cout << "Stack is empty";
//             exit(0);
//         }
//         int val = input.top();
//         input.pop();
//         return val;
//     }
//     // Return the Topmost element from the Queue
//     int Top()
//     {
//         if (input.empty())
//         {
//             cout << "Stack is empty";
//             exit(0);
//         }
//         return input.top();
//     }
//     // Return the size of the Queue
//     int size()
//     {
//         return input.size();
//     }
// };
// int main()
// {
//     Queue q;
//     q.Push(3);
//     q.Push(4);
//     cout << "The element poped is " << q.Pop() << endl;
//     q.Push(5);
//     cout << "The top of the queue is " << q.Top() << endl;
//     cout << "The size of the queue is " << q.size() << endl;
// }