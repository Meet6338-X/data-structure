#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSumHashMap(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int complement = target - nums[i];
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        numMap[nums[i]] = i;
    }
    return {}; // No solution found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSumHashMap(nums, target);
    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}