#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &arr)
    {
        int n = arr.size();
        int temp = 0, cnt = 0;
        vector<int> item;

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

            if (cnt > n / 3)
            {
                bool found = false;

                for (int k = 0; k < item.size(); k++)
                {
                    if (item[k] == temp)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    item.push_back(temp);
                }
            }

            cnt = 0;
        }
        return item;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {3, 2, 3};
    vector<int> result = s.majorityElement(arr);
    cout << "Majority elements (> n/3): ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}