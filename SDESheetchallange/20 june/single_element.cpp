#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicateBrute(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count == 1) {
                return nums[i];
            }
        }
        
        return -1;
    }
    
    int singleNonDuplicateBetter(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        
        return nums[n - 1];
    }
    
    int singleNonDuplicateOptimal(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    low = mid + 2;
                } else {
                    high = mid;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return nums[low];
    }
};

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    
    Solution sol;
    
    cout << "Single Element (Brute): " << sol.singleNonDuplicateBrute(nums) << endl;
    cout << "Single Element (Better): " << sol.singleNonDuplicateBetter(nums) << endl;
    cout << "Single Element (Optimal): " << sol.singleNonDuplicateOptimal(nums) << endl;
    
    return 0;
}