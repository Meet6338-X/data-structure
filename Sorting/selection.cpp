#include <iostream>
using namespace std;
void selection_s(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[7] = {30, 21, 28, 99, 70, 1, 5};
    int n = 7;
    selection_s(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// copy
//  #include <bits/stdc++.h>
//  using namespace std;
//  void selection_sort(int arr[], int n)
//  {
//      // selection sort
//      for (int i = 0; i < n - 1; i++)
//      {
//          int mini = i;
//          for (int j = i + 1; j < n; j++)
//          {
//              if (arr[j] < arr[mini])
//              {
//                  mini = j;
//              }
//          }
//          int temp = arr[mini];
//          arr[mini] = arr[i];
//          arr[i] = temp;
//      }
//      cout << "After selection sort: " << "\n";
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
//      cout << "Before selection sort: " << "\n";
//      for (int i = 0; i < n; i++)
//      {
//          cout << arr[i] << " ";
//      }
//      cout << "\n";
//      selection_sort(arr, n);
//      return 0;
//  }