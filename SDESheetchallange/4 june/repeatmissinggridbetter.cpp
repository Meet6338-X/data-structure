#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int n = grid.size();

        vector<int> freq(n * n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                freq[grid[i][j]]++;
            }
        }

        int repeat = -1, miss = -1;

        for (int i = 1; i <= n * n; i++)
        {
            if (freq[i] == 2)
                repeat = i;
            else if (freq[i] == 0)
                miss = i;
        }

        return {repeat, miss};
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 3}, {2, 2}};
    vector<int> result = s.findMissingAndRepeatedValues(grid);
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}