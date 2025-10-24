#include <iostream>
using namespace std;
int numsum = 0;
int i = 0;
void sumn(int n)
{
    i++;
    numsum += i;
    if (i >= n)
    {
        return;
    }
    else
    {
        sumn(n);
    }
}

int summ(int n)
{
    if(n==1)
    {
        return 1;
    }
    
    return n + summ(n-1);
}
int main()
{
    // sumn(5);
    // cout << numsum;
    cout<<summ(5);
}