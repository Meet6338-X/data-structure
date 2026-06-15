#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int i = 0, j = 0;
        int platforms = 0, ans = 0;

        while (i < n && j < n)
        {
            if (arr[i] <= dep[j])
            {
                platforms++;
                ans = max(ans, platforms);
                i++;
            }
            else
            {
                platforms--;
                j++;
            }
        }

        return ans;
    }
};