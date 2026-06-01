#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int largest(vector<int> &arr)
    {
        int max = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (max < arr[i])
            {
                max = arr[i];
            }
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {1, 5, 3, 9, 2, 8};
    cout << s.largest(arr) << endl;
    return 0;
}