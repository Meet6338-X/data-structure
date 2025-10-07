#include <iostream>
using namespace std;
int var = 1, i = 0;
void factorialm(int n)
{
    if (i >= n)
    {
        return;
    }
    else
    {
        i++;
        var *= i;
        cout << var << endl;
        factorialm(n);
    }
}
int main()
{
    factorialm(5);
}