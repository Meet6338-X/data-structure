#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    vector<int> JobScheduling(vector<vector<int>> &jobs)
    {

        sort(jobs.begin(), jobs.end(),
             [](auto &a, auto &b)
             {
                 return a[2] > b[2];
             });

        int maxDeadline = 0;

        for (auto &job : jobs)
            maxDeadline = max(maxDeadline, job[1]);

        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        for (auto &job : jobs)
        {

            int id = job[0];
            int deadline = job[1];
            int profit = job[2];

            for (int j = deadline; j >= 1; j--)
            {
                if (slot[j] == -1)
                {
                    slot[j] = id;
                    countJobs++;
                    totalProfit += profit;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};