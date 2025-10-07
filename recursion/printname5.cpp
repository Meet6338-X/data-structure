#include <iostream>
using namespace std;
void f1(int n, string name)
{
    if (n < 1)
    {
        return;
    }
    else
    {
        cout << n << name << endl;
        f1(n - 1, name);
    }
}
int main()
{
    f1(5, "Meet");
}