#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findCombination(int index,
                         int target,
                         vector<int> &candidates,
                         vector<int> &current,
                         vector<vector<int>> &result)
    {

        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++)
        {

            // Skip duplicates at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue further
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            findCombination(
                i + 1,
                target - candidates[i],
                candidates,
                current,
                result);

            current.pop_back(); // Backtrack
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> current;

        findCombination(
            0,
            target,
            candidates,
            current,
            result);

        return result;
    }
};