#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size() - 1; i++)
        {
            for (int j = i + 1; j < matrix.size(); j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
        return matrix;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result = s.rotateMatrix(matrix);
    cout << "Rotated matrix (90° anti-clockwise):" << endl;
    for (const auto& row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}