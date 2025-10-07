#include <iostream>
using namespace std;
void f2(int n)
{
    if (n < 1)
    {
        return;
    }
    else
    {
        cout << n << endl;
        f2(n - 1);
    }
}
int main()
{
    f2(100);
}