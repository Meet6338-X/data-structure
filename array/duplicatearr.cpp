#include <iostream>
#include <set> // set header file
using namespace std;
set<int> rmvduplicate(int arr[], int n)
{
    set<int> altu = {};
    for (int i = 0; i < n; i++)
    {
        altu.insert(arr[i]);
    }
    return altu;
}
int main()
{
    int arr[6] = {1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    set<int> res = rmvduplicate(arr, n);
    for (int val : res)
    {
        cout << val << " ";
    }
}

// bruteforce approach
// copy
//  int removeDuplicates(vector<int> &nums)
//  {
//      // Unordered set to store elements we have already seen
//      unordered_set<int> seen;

//     // Index where the next unique element will be written
//     int index = 0;

//     // Loop over each element in the array
//     for (int num : nums)
//     {
//         // If num is not in seen, it's unique
//         if (seen.find(num) == seen.end())
//         {
//             // Add this num to the set of seen numbers
//             seen.insert(num);

//             // Overwrite nums[index] with this unique num
//             nums[index] = num;

//             // Move index forward
//             index++;
//         }
//     }
//     // Return count of unique elements
//     return index;
// }
// O(N)

// optimal
// copy
//  int removeDuplicates(vector<int> &nums)
//  {
//      // If array is empty, return 0 directly
//      if (nums.empty())
//          return 0;

//     // Pointer for the position of last unique element
//     int i = 0;

//     // Traverse the array starting from the second element
//     for (int j = 1; j < nums.size(); j++)
//     {
//         // If current element is different from last unique element
//         if (nums[j] != nums[i])
//         {
//             // Move pointer for unique element forward
//             i++;
//             // Place the new unique element at the next position
//             nums[i] = nums[j];
//         }
//     }

//     // i is index of last unique element, count = i + 1
//     return i + 1;
// }
// O(n)

// count total cutting duplicate's
// int removeDuplicates(vector<int> &arr, int n)
// {
//     // Write your code here.
//     int i = 0;
//     for (int j = 1; j < n; j++)
//     {
//         if (arr[i] != arr[j])
//         {
//             swap(arr[i + 1], arr[j]);
//             i++;
//         }
//     }
//     return i + 1;
// };