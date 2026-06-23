#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> minAnd2ndMin(vector<int> &arr)
    {
        int small = INT_MAX;
        int sec = INT_MAX;

        for (int x : arr)
        {
            if (x < small)
            {
                sec = small;
                small = x;
            }
            else if (x > small && x < sec)
            {
                sec = x;
            }
        }

        if (sec == INT_MAX)
            return {-1};

        return {small, sec};
    }
};

// Input: arr[] = [2, 4, 3, 5, 6]
// Output: [2, 3]
// Explanation: 2 and 3 are respectively the smallest and second smallest elements in the array.
// Input: arr[] = [1, 1, 1]
// Output: [-1]
// Explanation: Only element is 1 which is smallest, so there is no second smallest element.
