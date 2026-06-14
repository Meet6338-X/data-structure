#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnesBrute(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 1) {
                    count++;
                } else {
                    break;
                }
            }
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
    
    int findMaxConsecutiveOnesBetter(vector<int>& nums) {
        int maxCount = 0;
        int currentCount = 0;
        
        for (int num : nums) {
            if (num == 1) {
                currentCount++;
                maxCount = max(maxCount, currentCount);
            } else {
                currentCount = 0;
            }
        }
        
        return maxCount;
    }
    
    int findMaxConsecutiveOnesOptimal(vector<int>& nums) {
        return findMaxConsecutiveOnesBetter(nums);
    }
};

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    
    Solution sol;
    
    cout << "Max Consecutive Ones (Brute): " << sol.findMaxConsecutiveOnesBrute(nums) << endl;
    cout << "Max Consecutive Ones (Better): " << sol.findMaxConsecutiveOnesBetter(nums) << endl;
    cout << "Max Consecutive Ones (Optimal): " << sol.findMaxConsecutiveOnesOptimal(nums) << endl;
    
    return 0;
}