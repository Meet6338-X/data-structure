#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int cp = 0;
        int cop = 0;
        while (cp < g.size() && cop < s.size())
        {
            if (g[cp] <= s[cop])
            {
                cp++;
            }
            cop++;
        }
        return cp;
    }
};