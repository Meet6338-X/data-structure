#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        int f2 = 0;

        for (int f1 = 0; f1 < arr.size(); f1++)
        {
            if (arr[f1] == 0)
            {
                swap(arr[f1], arr[f2]);
                f2++;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    sol.segregate0and1(arr);

    cout << "After segregation: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}