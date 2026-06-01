class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int officer = 0;

        for (int CM = 1; CM < nums.size(); CM++)
        {
            if (nums[CM] != nums[officer])
            {
                officer++;
                nums[officer] = nums[CM];
            }
        }

        return officer + 1;
    }
};