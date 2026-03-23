// LC : 191
//  https : // leetcode.com/problems/number-of-1-bits/description/
#include <iostream>
#include <bitset>
using namespace std;
class Solution
{
public:
    int hammingWeight(int n)
    {
        bitset<32> binary(n);
        int count = 0;
        for (int i = 0; i < binary.size(); i++)
        {
            if (binary[i] == 1)
            {
                count++;
            }
        }
        return count;
    }
};