#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        int temp = 0, cnt = 0, item = -1;
        for (int i = 0; i < n; i++)
        {
            temp = arr[i];
            for (int j = 0; j < n; j++)
            {
                if (temp == arr[j])
                {
                    cnt++;
                }
            }
            if (cnt > n / 2)
            {
                item = temp;
                break;
            }
            cnt = 0;
        }
        return item;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    cout << s.majorityElement(arr) << endl;
    return 0;
}