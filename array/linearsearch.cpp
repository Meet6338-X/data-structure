#include <iostream>
using namespace std;
void linearsearch(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            cout << arr[i] << " at index " << i;
        }
        else
        {
            cout << "element not found";
            break;
        }
    }
}
int main()
{
    int arr[7] = {3, 1, 7, 10, 8, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    linearsearch(arr, n, 111);
}