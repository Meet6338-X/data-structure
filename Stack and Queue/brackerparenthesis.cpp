#include <iostream>
using namespace std;

class impstackarray
{
public:
    int top;
    char st[1000];

    impstackarray()
    {
        top = -1;
    }

    void push(char val)
    {
        if (top >= 999)
        {
            cout << "Overflow\n";
            return;
        }
        st[++top] = val;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Underflow\n";
            return;
        }
        top--;
    }

    char peek()
    {
        if (top < 0)
        {
            return '\0';
        }
        return st[top];
    }

    bool empty()
    {
        return top == -1;
    }

    bool checkbracket(string exp)
    {
        for (int i = 0; i < exp.length(); i++)
        {
            char ch = exp[i];
            if (ch == '(' || ch == '{' || ch == '[')
            {
                push(ch);
            }
            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (empty())
                {
                    return false;
                }

                char topch = peek();
                if ((ch == ')' && topch == '(') ||
                    (ch == '}' && topch == '{') ||
                    (ch == ']' && topch == '['))
                {
                    pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return empty();
    }
};

int main()
{
    impstackarray s;
    // chatgpt testing
    string exp1 = "{[()]}";
    string exp2 = "{[(])}";
    string exp3 = "((a+b)*[c-d])";

    cout << exp1 << " → " << (s.checkbracket(exp1) ? "Balanced " : "Not Balanced ") << endl;
    cout << exp2 << " → " << (s.checkbracket(exp2) ? "Balanced " : "Not Balanced ") << endl;
    cout << exp3 << " → " << (s.checkbracket(exp3) ? "Balanced " : "Not Balanced ") << endl;

    return 0;
}

// copy
//  #include <bits/stdc++.h>
//  using namespace std;
//  bool isValid(string s)
//  {
//      stack<char> st;
//      for (auto it : s)
//      {
//          if (it == '(' || it == '{' || it == '[')
//              st.push(it);
//          else
//          {
//              if (st.size() == 0)
//                  return false;
//              char ch = st.top();
//              st.pop();
//              if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or (it == '}' and ch == '{'))
//                  continue;
//              else
//                  return false;
//          }
//      }
//      return st.empty();
//  }
//  int main()
//  {
//      string s = "()[{}()]";
//      if (isValid(s))
//          cout << "True" << endl;
//      else
//          cout << "False" << endl;
//  }