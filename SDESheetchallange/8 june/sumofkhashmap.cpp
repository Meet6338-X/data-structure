#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int count = 0;
        int currentSum = 0;
        
        for (int num : nums)
        {
            currentSum += num;
            if (prefixSumCount.find(currentSum - k) != prefixSumCount.end())
            {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }
        return count;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    Solution sol;
    cout << sol.subarraySum(nums, k) << endl;
    return 0;
}