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

int factorial2f(int n) 
{
    if (n == 0 || n == 1)
        return 1;
    
    
    return n * factorial2f(n - 1);
}

int main()
{
    // factorialm(5);
    cout<< factorial2f(5);
}