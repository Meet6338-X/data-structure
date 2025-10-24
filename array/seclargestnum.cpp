#include <iostream>
using namespace std;

int largestt(int arr[], int n)
{
    int lar = arr[0];
    int slar = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (lar < arr[i])
        {
            lar = arr[i];
        }
        if (arr[i] > slar && arr[i] != lar)
        {
            slar = arr[i];
        }
    }
    return slar;
}

int main()
{
    int arr[5] = {110, 19, 20, 50, 190};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << largestt(arr, n);
}