#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);
        int posIdx = 0, negIdx = 1;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
            else
            {
                ans[negIdx] = nums[i];
                negIdx += 2;
            }
        }

        // Copy back to nums
        for (int i = 0; i < n; i++)
        {
            nums[i] = ans[i];
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

// Time Complexity: O(n) - single pass through the array
// Space Complexity: O(n) - for the ans vector
