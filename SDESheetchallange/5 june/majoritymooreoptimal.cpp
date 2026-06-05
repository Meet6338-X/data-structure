#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int freq = 0, ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (freq == 0)
            {
                ans = nums[i];
            }
            if (ans == nums[i])
            {
                freq++;
            }
            else
            {
                freq--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(nums) << endl;
    return 0;
}