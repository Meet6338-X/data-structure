#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getSecondLargest(vector<int> &arr)
    {
        int largest = -1;
        int secondLargest = -1;

        for (int num : arr)
        {
            if (num > largest)
            {
                secondLargest = largest;
                largest = num;
            }
            else if (num < largest && num > secondLargest)
            {
                secondLargest = num;
            }
        }

        return secondLargest;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << s.getSecondLargest(arr) << endl;
    return 0;
}