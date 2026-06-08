#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubarraysXOR(vector<int> &A, int B)
    {
        int count = 0;
        for (int i = 0; i < A.size(); i++)
        {
            int xorVal = 0;
            for (int j = i; j < A.size(); j++)
            {
                xorVal ^= A[j];
                if (xorVal == B)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> A = {4, 2, 2, 6, 4};
    int B = 6;

    Solution sol;
    cout << sol.countSubarraysXOR(A, B) << endl;
    return 0;
}