#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size() - 1; i++)
        {
            for (int j = i + 1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    s.rotate(matrix);
    cout << "Rotated matrix (90° clockwise):" << endl;
    for (const auto& row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}