#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &A, int k)
    {
        unordered_map<int, int> freq;
        freq[0] = 1;

        int prefixXor = 0;
        int count = 0;

        for (int num : A)
        {
            prefixXor ^= num;
            int target = prefixXor ^ k;

            if (freq.find(target) != freq.end())
            {
                count += freq[target];
            }

            freq[prefixXor]++;
        }
        return count;
    }
};

int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int k = 6;
    Solution sol;
    cout << sol.countSubarrays(A, k) << endl;
    return 0;
}