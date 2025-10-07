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
int main()
{
    sumn(5);
    cout << numsum;
}