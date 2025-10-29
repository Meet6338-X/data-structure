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

// map
// copy
//  vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
//  {
//      map<int, int> freq;
//      vector<int> Union;
//      for (int i = 0; i < n; i++)
//          freq[arr1[i]]++;
//      for (int i = 0; i < m; i++)
//          freq[arr2[i]]++;
//      for (auto &it : freq)
//          Union.push_back(it.first);
//      return Union;
//  }

// two pointer method
// copy
// vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
// {
//     int i = 0, j = 0;  // pointers
//     vector<int> Union; // Uninon vector
//     while (i < n && j < m)
//     {
//         if (arr1[i] <= arr2[j]) // Case 1 and 2
//         {
//             if (Union.size() == 0 || Union.back() != arr1[i])
//                 Union.push_back(arr1[i]);
//             i++;
//         }
//         else // case 3
//         {
//             if (Union.size() == 0 || Union.back() != arr2[j])
//                 Union.push_back(arr2[j]);
//             j++;
//         }
//     }
//     while (i < n) // IF any element left in arr1
//     {
//         if (Union.back() != arr1[i])
//             Union.push_back(arr1[i]);
//         i++;
//     }
//     while (j < m) // If any elements left in arr2
//     {
//         if (Union.back() != arr2[j])
//             Union.push_back(arr2[j]);
//         j++;
//     }
//     return Union;
// }