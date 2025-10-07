#include <iostream>
using namespace std;
void f3(int i, int n)
{
    if (i >= n)
    {
        return;
    }
    else
    {
        cout << i << endl;
        f3(i + 1, n);
    }
}

int main()
{
    f3(1, 140);
}