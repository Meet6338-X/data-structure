#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void queen(vector<vector<string>> &ans, int idx, int n, vector<int> &v, vector<string> &e)
    {
        if (idx == n)
        {
            ans.push_back(e);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            int u = 0;
            for (int i = 0; i < idx; i++)
            {
                if (j == v[i] + idx - i || j == v[i] - idx + i || j == v[i])
                    u = 1;
            }
            if (u)
                continue;
            v.push_back(j);
            string s(n, '.');
            s[j] = 'Q';
            e.push_back(s);
            queen(ans, idx + 1, n, v, e);
            v.pop_back();
            e.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<int> v;
        vector<string> e;
        queen(ans, 0, n, v, e);
        return ans;
    }
};