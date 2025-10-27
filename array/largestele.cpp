#include <iostream>
using namespace std;

int largestt(int arr[], int n)
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

int main()
{
    int arr[5] = {110, 19, 20, 50, 190};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << largestt(arr, n);
}

// copy - brute force approch
//  #include <bits/stdc++.h>
//  using namespace std;

// int sortArr(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     return arr[arr.size() - 1];
// }

// int main()
// {
//     vector<int> arr1 = {2, 5, 1, 3, 0};
//     vector<int> arr2 = {8, 10, 5, 7, 9};

//     cout << "The Largest element in the array is: " << sortArr(arr1) << endl;
//     cout << "The Largest element in the array is: " << sortArr(arr2);

//     return 0;
// }

// #include <algorithm> // Required for std::max_element also sort
// max_element(arr.begin(), arr.end())
// sort(arr.begin(), arr.end());
