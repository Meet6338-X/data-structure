// LC : 268
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != start)
            {
                return start;
            }
            start++;
        }
        return start;
    }
};

int main()
{
    Solution sol;

    // Test case 1: Basic case
    vector<int> nums1 = {3, 0, 1};
    cout << "Test 1 - Missing number: " << sol.missingNumber(nums1) << endl;

    // Test case 2: Missing number is 2
    vector<int> nums2 = {0, 1};
    cout << "Test 2 - Missing number: " << sol.missingNumber(nums2) << endl;

    // Test case 3: Missing number is 4
    vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Test 3 - Missing number: " << sol.missingNumber(nums3) << endl;

    // Test case 4: Single element
    vector<int> nums4 = {0};
    cout << "Test 4 - Missing number: " << sol.missingNumber(nums4) << endl;

    // Test case 5: Missing number is 1
    vector<int> nums5 = {0, 2};
    cout << "Test 5 - Missing number: " << sol.missingNumber(nums5) << endl;

    return 0;
}

/*
================================================================================
OPTIMAL APPROACH - XOR Method
================================================================================

Problem: Given an array of n distinct integers in range [0, n], find the
         missing number.

Current Approach (Sorting):
- Sort the array
- Iterate through and find where nums[i] != i
- Time: O(n log n), Space: O(1) or O(log n) depending on sort implementation

Optimal Approach 1: XOR Method
- XOR all numbers from 0 to n
- XOR all elements in the array
- XOR of these two results gives the missing number

Why XOR works:
- XOR of a number with itself is 0 (a ^ a = 0)
- XOR of 0 with a number is the number itself (a ^ 0 = a)
- XOR is commutative and associative
- All numbers except the missing one will appear twice (once in range, once in array)
- They cancel out, leaving only the missing number

Time Complexity: O(n) - Single pass through array
Space Complexity: O(1) - Only uses a few variables

Code:
int missingNumber(vector<int>& nums) {
    int xorAll = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        xorAll ^= i ^ nums[i];
    }
    return xorAll;
}

Optimal Approach 2: Sum Formula
- Calculate expected sum = n * (n + 1) / 2
- Calculate actual sum of array elements
- Missing number = expected sum - actual sum

Time Complexity: O(n)
Space Complexity: O(1)

Code:
int missingNumber(vector<int>& nums) {
    int expectedSum = nums.size() * (nums.size() + 1) / 2;
    int actualSum = 0;
    for (int num : nums) {
        actualSum += num;
    }
    return expectedSum - actualSum;
}

Note: XOR approach is preferred over sum formula because:
- No risk of integer overflow for large n
- Works correctly with negative numbers (if applicable)
================================================================================
*/