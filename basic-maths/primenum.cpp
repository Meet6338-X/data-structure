#include <iostream>
using namespace std;

// function declaration
void primee(int n);

int main()
{
    for (int n = -1; n <= 100; n++)
    {
        cout << n << " : ";
        primee(n);
        cout << endl;
    }
    return 0;
}

void primee(int n)
{
    if (n <= 1)
    {
        cout << "Not prime";
        return;
    }

    if (n == 2)
    {
        cout << "Prime number";
        return;
    }

    if (n % 2 == 0)
    {
        cout << "Not prime";
        return;
    }

    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            cout << "Not prime";
            return;
        }
    }

    cout << "Prime number";
}