#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class Queue
{
public:
    node *front, *rear;
    int size;

    Queue()
    {
        front = rear = nullptr;
        size = 0;
    }

    void enqueue(int val)
    {
        node *temp = new node(val);
        if (rear == nullptr)
        {
            front = rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
        size++;
    }

    void dequeue()
    {
        if (front == nullptr)
            return;
        node *temp = front;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        size--;
    }

    int peek()
    {
        if (front == nullptr)
            return -1;
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    int getSize()
    {
        return size;
    }
};

// change's in stack
class Stack
{
    Queue q;
    // generated one queue

public:
    void push(int val)
    {
        int n = q.getSize();
        q.enqueue(val);

        // Rotate elements to bring new one to front
        for (int i = 0; i < n; i++)
        {
            int temp = q.peek();
            q.dequeue();
            q.enqueue(temp);
        }
        cout << val << " pushed to stack\n";
    }

    void pop()
    {
        if (q.isEmpty())
        {
            cout << "Stack underflow\n";
            return;
        }
        cout << q.peek() << " popped from stack\n";
        q.dequeue();
    }

    void top()
    {
        if (q.isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Top element: " << q.peek() << endl;
    }

    void size()
    {
        cout << "Stack size: " << q.getSize() << endl;
    }

    void display()
    {
        if (q.isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        node *temp = q.front;
        cout << "Stack elements (top to bottom): ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // gpt
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();
    st.top();
    st.size();

    st.pop();
    st.display();
    st.top();
    st.size();

    st.pop();
    st.pop();
    st.pop();

    return 0;
}

// copy
//  #include <bits/stdc++.h>

// using namespace std;

// class Stack
// {
//     queue<int> q;

// public:
//     void Push(int x)
//     {
//         int s = q.size();
//         q.push(x);
//         for (int i = 0; i < s; i++)
//         {

//             q.push(q.front());
//             q.pop();
//         }
//     }
//     int Pop()
//     {
//         int n = q.front();
//         q.pop();
//         return n;
//     }
//     int Top()
//     {
//         return q.front();
//     }
//     int Size()
//     {
//         return q.size();
//     }
// };

// int main()
// {
//     Stack s;
//     s.Push(3);
//     s.Push(2);
//     s.Push(4);
//     s.Push(1);
//     cout << "Top of the stack: " << s.Top() << endl;
//     cout << "Size of the stack before removing element: " << s.Size() << endl;
//     cout << "The deleted element is: " << s.Pop() << endl;
//     cout << "Top of the stack after removing element: " << s.Top() << endl;
//     cout << "Size of the stack after removing element: " << s.Size();
// }