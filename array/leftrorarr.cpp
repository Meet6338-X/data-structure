#include <iostream>
using namespace std;
void leftror(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}
int main()
{
    int arr[7] = {1, 2, 3, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    leftror(arr, n);
    for (int j = 0; j < n; j++)
    {
        cout << arr[j];
    }
    return 0;
}