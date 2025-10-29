#include <iostream>
using namespace std;

void movezero(int arr[], int n)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[index] = arr[i];
            index++;
        }
    }
    while (index < n)
    {
        arr[index] = 0;
        index++;
    }
}

void optimalzero(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main()
{
    int arr[7] = {3, 0, 0, 7, 8, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    optimalzero(arr, n);
    cout << "after array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}