#include <iostream>
using namespace std;
class impstackarray
{
public:
    int top = -1;
    int st[1000];
    int x = sizeof(st) / sizeof(st[0]);
    void push(int val)
    {
        if (top > x)
        {
            cout << "overflow";
        }
        top++;
        st[top] = val;
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "emty";
        }
        cout << st[top] << " is poped" << endl;
        top--;
    }
    void sizei()
    {
        cout << "size = " << top + 1 << endl;
    }
    void stackdisplay()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << "stack " << i << " = " << st[i] << endl;
        }
    }
};

int main()
{
    impstackarray iost;
    iost.push(6);
    iost.push(90);
    iost.push(70);
    iost.sizei();
    iost.stackdisplay();
    iost.pop();
    iost.stackdisplay();
}

// copy
//  class Stack
//  {
//      int size;
//      int *arr;
//      int top;

// public:
//     Stack()
//     {
//         top = -1;
//         size = 1000;
//         arr = new int[size];
//     }
//     void push(int x)
//     {
//         top++;
//         arr[top] = x;
//     }
//     int pop()
//     {
//         int x = arr[top];
//         top--;
//         return x;
//     }
//     int Top()
//     {
//         return arr[top];
//     }
//     int Size()
//     {
//         return top + 1;
//     }
// };