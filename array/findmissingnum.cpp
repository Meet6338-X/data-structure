#include <iostream>
using namespace std;

void findnum(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int current = arr[i];
        int next = arr[i + 1];

        while (current + 1 < next)
        {
            cout << current + 1 << " ";
            current++;
        }
    }
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 6, 7, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    findnum(arr, n);
    return 0;
}

// brute force approach
//  int missingNumber(vector<int> &a, int N)
//  {
//      for (int i = 1; i <= N; i++)
//      {
//          int flag = 0;

//         for (int j = 0; j < N - 1; j++)
//         {
//             if (a[j] == i)
//             {

//                 // i is present in the array:
//                 flag = 1;
//                 break;
//             }
//         }
//         if (flag == 0)
//             return i;
//     }
//     return -1;
// }

// using hashing
// int missingNumber(vector<int> &a, int N)
// {
//     int hash[N + 1] = {0};
//     for (int i = 0; i < N - 1; i++)
//         hash[a[i]]++;
//     for (int i = 1; i <= N; i++)
//     {
//         if (hash[i] == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }
