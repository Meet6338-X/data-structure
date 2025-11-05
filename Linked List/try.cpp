#include <iostream>
using namespace std;
int main()
{
    int b = 20;
    int *p = &b;
    cout << *p;
    cout << nullptr;
    return 0;
}