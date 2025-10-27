#include <iostream>
#include <vector>
using namespace std;
vector<int> rotateArray(vector<int> arr, int n, int k)
{
    // Write your code here.
    k = k % n;
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }
    return arr;
}

int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 7, 8};
    int n = arr.size();
    arr = rotateArray(arr, n, 2);
    for (int j = 0; j < n; j++)
    {
        cout << arr[j];
    }
    return 0;
}