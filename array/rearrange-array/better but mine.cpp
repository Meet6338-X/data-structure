#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        int arr1[n / 2]; // positive
        int arr2[n / 2]; // negative
        int f1 = 0, f2 = 0, flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                arr2[f2] = nums[i];
                f2++;
            }
            else
            {
                arr1[f1] = nums[i];
                f1++;
            }
        }
        f1 = 0, f2 = 0;
        for (int j = 0; j < n; j++)
        {
            if (flag == 0)
            {
                nums[j] = arr1[f1];
                f1++;
                flag = 1;
            }
            else
            {
                nums[j] = arr2[f2];
                f2++;
                flag = 0;
            }
        }
        return nums;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, 2, -3, 4, 5, 6, -7, 8, 9};

    cout << "Original array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    sol.rearrangeArray(nums);

    cout << "Rearranged array: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}

// Time Complexity: O(n) - where n is the size of the array
// Space Complexity: O(n) - for storing positive and negative arrays
