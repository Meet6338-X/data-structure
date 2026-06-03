#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> answer;
        int n = intervals.size();
        for (int i = 0; i < n;)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
                j++;
            }
            answer.push_back({start, end});
            i = j;
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = s.merge(intervals);
    cout << "Merged intervals: ";
    for (const auto& interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}