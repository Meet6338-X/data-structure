// Example Array: [2, 5, 1, 7, 10]
// Value of K: 10
// The Question: Find the longest subarray where the sum of its elements is less than or equal to K.
#include <iostream>
using namespace std;
int main()
{
    int arr[5] = {2, 5, 1, 7, 10};
    int k = 17;
    int n = 5, sum = 0, maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (sum <= k)
            {
                maxlen = max(maxlen, j - i + 1);
            }
            else if (sum > k)
            {
                break;
            }
        }
    }
    cout << maxlen;
    return 0;
}