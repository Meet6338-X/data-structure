#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "After Using bubble sort: " << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int n;
    cin >> n;
    int arr[n] = {30, 50, 1, 3, 80};
    bubblesort(arr, n);
}

// copy
//  #include <bits/stdc++.h>
//  using namespace std;
//  void bubble_sort(int arr[], int n)
//  {
//      for (int i = n - 1; i >= 0; i--)
//      {
//          int didSwap = 0;
//          for (int j = 0; j <= i - 1; j++)
//          {
//              if (arr[j] > arr[j + 1])
//              {
//                  int temp = arr[j + 1];
//                  arr[j + 1] = arr[j];
//                  arr[j] = temp;
//                  didSwap = 1;
//              }
//          }
//          if (didSwap == 0)
//          {
//              break;
//          }
//      }
//      cout << "After Using bubble sort: " << "\n";
//      for (int i = 0; i < n; i++)
//      {
//          cout << arr[i] << " ";
//      }
//      cout << "\n";
//  }
//  int main()
//  {
//      int arr[] = {13, 46, 24, 52, 20, 9};
//      int n = sizeof(arr) / sizeof(arr[0]);
//      cout << "Before Using Bubble Sort: " << endl;
//      for (int i = 0; i < n; i++)
//      {
//          cout << arr[i] << " ";
//      }
//      cout << endl;
//     bubble_sort(arr, n);
//     return 0;
// }