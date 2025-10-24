#include <iostream>
using namespace std;
// 509 leetcode
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int fibr(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int ans;
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
        if (i == n)
        {
            ans = c;
            break;
        }
    }

    return ans;
}

int main()
{
    cout << fibr(6) << endl;
    cout << fib(4);
    return 0;
}