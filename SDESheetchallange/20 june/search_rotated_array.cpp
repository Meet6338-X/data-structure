#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchBrute(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
    
    int searchBetter(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        
        if (pivot == -1) {
            return binarySearch(nums, 0, nums.size() - 1, target);
        }
        
        if (nums[pivot] == target) {
            return pivot;
        }
        
        if (target >= nums[0]) {
            return binarySearch(nums, 0, pivot - 1, target);
        }
        
        return binarySearch(nums, pivot + 1, nums.size() - 1, target);
    }
    
    int searchOptimal(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (target >= nums[mid] && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return -1;
    }

private:
    int findPivot(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
    
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    Solution sol;
    
    cout << "Search in Rotated Array (Brute): " << sol.searchBrute(nums, target) << endl;
    cout << "Search in Rotated Array (Better): " << sol.searchBetter(nums, target) << endl;
    cout << "Search in Rotated Array (Optimal): " << sol.searchOptimal(nums, target) << endl;
    
    return 0;
}