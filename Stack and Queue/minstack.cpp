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
        if (top >= x - 1)
        {
            cout << "Overflow\n";
            return;
        }
        top++;
        st[top] = val;
        cout << val << " pushed\n";
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Empty Stack\n";
            return;
        }
        cout << st[top] << " is popped\n";
        top--;
    }

    void sizei()
    {
        cout << "Size = " << top + 1 << endl;
    }

    void stackdisplay()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++)
        {
            cout << st[i] << " ";
        }
        cout << endl;
    }

    void getmin()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return;
        }

        int tempp = st[0];
        for (int i = 1; i <= top; i++)
        {
            if (st[i] < tempp)
            {
                tempp = st[i];
            }
        }
        cout << "Minimum element = " << tempp << endl;
    }
};

int main()
{
    impstackarray s;
    // gpt
    s.push(10);
    s.push(5);
    s.push(20);
    s.push(2);
    s.push(8);

    s.stackdisplay();

    s.getmin();

    s.pop();
    s.pop();

    s.stackdisplay();

    s.getmin();

    s.sizei();

    return 0;
}

// 🧠 Solution 1 — Using Pair Stack (O(2N) Space)
// We store two things for every element:
// The element’s value
// The minimum value up to this point.
// class MinStack
// {
//     stack<pair<int, int>> st;

// public:
//     void push(int x)
//     {
//         int min;
//         if (st.empty())
//         {
//             min = x;
//         }
//         else
//         {
//             min = std::min(st.top().second, x);
//         }
//         st.push({x, min});
//     }

//     void pop()
//     {
//         st.pop();
//     }

//     int top()
//     {
//         return st.top().first;
//     }

//     int getMin()
//     {
//         return st.top().second;
//     }
// };

// ⚡ Solution 2 — Using Encoded Value(O(N) Space)
//     Store only one value per element but encode information about the minimum in the value itself.
//     We also keep a separate variable mini to track the current minimum.
// class MinStack
// {
//     stack<long long> st;
//     long long mini;

// public:
//     /** initialize your data structure here. */
//     MinStack()
//     {
//         while (st.empty() == false)
//             st.pop();
//         mini = INT_MAX;
//     }

//     void push(int value)
//     {
//         long long val = Long.valuevalue;
//         if (st.empty())
//         {
//             mini = val;
//             st.push(val);
//         }
//         else
//         {
//             if (val < mini)
//             {
//                 st.push(2 * val * 1LL - mini);
//                 mini = val;
//             }
//             else
//             {
//                 st.push(val);
//             }
//         }
//     }

//     void pop()
//     {
//         if (st.empty())
//             return;
//         long long el = st.top();
//         st.pop();

//         if (el < mini)
//         {
//             mini = 2 * mini - el;
//         }
//     }

//     int top()
//     {
//         if (st.empty())
//             return -1;

//         long long el = st.top();
//         if (el < mini)
//             return mini;
//         return el;
//     }

//     int getMin()
//     {
//         return mini;
//     }
// };