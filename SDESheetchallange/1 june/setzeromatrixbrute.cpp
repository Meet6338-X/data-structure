#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {

                    for (int k = 0; k < cols; k++)
                    {
                        if (matrix[i][k] != 0)
                            matrix[i][k] = -69;
                    }

                    for (int k = 0; k < rows; k++)
                    {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = -69;
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == -69)
                    matrix[i][j] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    s.setZeroes(matrix);
    for (auto row : matrix)
    {
        for (auto val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}