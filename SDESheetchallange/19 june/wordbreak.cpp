#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool breaks(string &s, unordered_set<string> &dict, int st)
    {
        int n = s.length();
        string word = "";

        for (int i = st; i < n; i++)
        {
            word += s[i];

            if (dict.find(word) != dict.end())
            {
                if (i == n - 1)
                    return true;

                if (i < n - 1 && breaks(s, dict, i + 1))
                    return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return breaks(s, dict, 0);
    }
};