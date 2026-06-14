#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicatesBrute(vector<int>& nums) {
        vector<int> temp;
        for (int num : nums) {
            if (temp.empty() || temp.back() != num) {
                temp.push_back(num);
            }
        }
        
        for (int i = 0; i < temp.size(); i++) {
            nums[i] = temp[i];
        }
        
        return temp.size();
    }
    
    int removeDuplicatesBetter(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }
        
        return j + 1;
    }
    
    int removeDuplicatesOptimal(vector<int>& nums) {
        return removeDuplicatesBetter(nums);
    }
};

int main() {
    vector<int> nums = {1, 1, 2};
    
    Solution sol;
    
    vector<int> nums1 = nums;
    int len1 = sol.removeDuplicatesBrute(nums1);
    cout << "Brute: " << len1 << " - ";
    for (int i = 0; i < len1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;
    
    vector<int> nums2 = nums;
    int len2 = sol.removeDuplicatesBetter(nums2);
    cout << "Better: " << len2 << " - ";
    for (int i = 0; i < len2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;
    
    vector<int> nums3 = nums;
    int len3 = sol.removeDuplicatesOptimal(nums3);
    cout << "Optimal: " << len3 << " - ";
    for (int i = 0; i < len3; i++) {
        cout << nums3[i] << " ";
    }
    cout << endl;
    
    return 0;
}