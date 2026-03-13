// Problem Statement : Given an array, we have to find the largest element in the array.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {6, 5, 1, 3, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    largestElement(arr, n);
    return 0;
}

int largestElement(vector<int> &arr, int n)
{
    int lar = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (lar < arr[i])
        {
            lar = arr[i];
        }
    }
    return lar;
}
