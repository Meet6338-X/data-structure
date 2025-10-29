#include <iostream>
using namespace std;

int main()
{
    int arr[7] = {3, 1, 7, 10, 8, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    optimalzero(arr, n);
    cout << "after array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}