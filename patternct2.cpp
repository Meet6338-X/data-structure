#include <iostream>
using namespace std;
int pattern1(int n)
{
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    // * * * * *
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int pattern2(int n)
{
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    // * * * * * *
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int pattern3(int n)
{
    // 1
    // 12
    // 123
    // 1234
    // 12345
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
int pattern4(int n)
{
    // 1
    // 22
    // 333
    // 4444
    // 55555
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
int pattern5(int n)
{
    // * * * * *
    // * * * *
    // * * *
    // * *
    // *
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int pattern6(int n)
{
    // 1234
    // 123
    // 12
    // 1
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j < n - i + 1; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}
int pattern7(int n)
{
    //      *
    //     ***
    //    *****
    //   *******
    //  *********
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
int pattern8(int n)
{
    // * * * * *
    //  * * * *
    //   * * *
    //    * *
    //     *
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < n - i; k++)
        {
            cout << "* ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
int main()
{
    int n = 5;
    // pattern1(5);
    // pattern2(n);
    // pattern3(n);
    // pattern4(n);
    // pattern5(n);
    // pattern6(n);
    pattern7(n);
}