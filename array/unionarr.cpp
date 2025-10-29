#include <iostream>
#include <set>
using namespace std;
void unionarr(int arr[], int arr1[], int n, int n1)
{
    set<int> ans = {};
    for (int i = 0; i < n; i++)
    {
        ans.insert(arr[i]);
    }
    for (int j = 0; j < n1; j++)
    {
        ans.insert(arr1[j]);
    }
    for (int val : ans)
        cout << val << " ";
    cout << endl;
}
int main()
{
    int arr[7] = {3, 1, 7, 10, 8, 0, 9};
    int arr1[8] = {2, 1, 6, 3, 22, 5, 10, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int n1 = sizeof(arr1) / sizeof(arr[0]);
    unionarr(arr, arr1, n, n1);
}

void solution3(int arr[], int arr1[], int n, int n1)
{
}