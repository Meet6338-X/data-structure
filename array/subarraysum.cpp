#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> subarraySum(vector<int> &arr, int target)
    {
        int left = 0, right = 0;
        long long sum = 0;

        while (right < arr.size())
        {
            sum += arr[right];

            while (sum > target && left <= right)
            {
                sum -= arr[left];
                left++;
            }

            if (sum == target)
            {
                return {left + 1, right + 1};
            }

            right++;
        }

        return {-1};
    }
};