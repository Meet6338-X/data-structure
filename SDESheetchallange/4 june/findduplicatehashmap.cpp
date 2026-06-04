#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        vector<int> hashlist(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++)
        {
            if (hashlist[nums[i]] == 0)
            {
                hashlist[nums[i]]++;
            }
            else
            {
                return nums[i];
            }
        }

        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, 4, 2, 2};
    cout << s.findDuplicate(nums) << endl;
    return 0;
}