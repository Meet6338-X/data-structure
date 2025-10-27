#include <vector>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0)
        return;
    k = k % n;
    if (k == 0)
        return;

    // store last k elements
    vector<int> temp(k);
    for (int i = 0; i < k; ++i)
    {
        temp[i] = nums[n - k + i];
    }

    // shift the rest to the right
    for (int i = n - 1; i >= k; --i)
    {
        nums[i] = nums[i - k];
    }

    // copy temp to front
    for (int i = 0; i < k; ++i)
    {
        nums[i] = temp[i];
    }
}