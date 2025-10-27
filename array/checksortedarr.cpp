#include <iostream>
using namespace std;
// optimal appraoch
bool checkarr(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << checkarr(arr, n);
}

// bruteforce approach
//  bool cheackarr(int arr[], int n)
//  {
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = i + 1; j < n; j++)
//          {
//              if (arr[j] < arr[i])
//                  return false;
//          }
//      }
//     return true;
// }