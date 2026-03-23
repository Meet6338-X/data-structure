// Array: [-1, 2, 3, 3] (Note: The array is shown with a size of 4 for the initial window, with the full array actually being [-1, 2, 3, 3, 4, 1] based on later context).
// Integer k: 4 (This represents the constant window size).
// Question: Given an array with positive and negative integers and an integer K, figure out the maximum sum that can be obtained by picking up K elements consecutively.
// #include <iostream>
// using namespace std;
// int main()
// {
//     int arr[7] = {-1, 2, 3, 3, 4, 5, -1};
//     int k = 4;

//     int sum = 0;
//     for (int i = 0; i < k; i++)
//     {
//         sum += arr[i];
//     }
//     int maxx = sum;

//     for (int i = k; i < 7; i++)
//     {
//         sum = sum - arr[i - k] + arr[i];
//         maxx = max(maxx, sum);
//     }

//     cout << maxx;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// LC : 643 return maxsum/k for average

int findMaxSum(const vector<int> &arr, int k)
{
    int n = arr.size();

    if (n < k)
    {
        return -1;
    }

    int current_sum = 0;
    for (int i = 0; i < k; i++)
    {
        current_sum += arr[i];
    }

    int max_sum = current_sum;
    int l = 0;
    int r = k - 1;

    // 2. Slide the window (while r < n - 1)
    while (r < n - 1)
    {
        // Subtract the element leaving the window (l)
        current_sum -= arr[l];
        l++;

        // Add the element entering the window (r+1)
        r++;
        current_sum += arr[r];

        // Update the maximum sum found so far
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> arr = {-1, 2, 3, 3, 4, 5, -1};
    int k = 4;

    int result = findMaxSum(arr, k);

    cout << "Maximum Sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}