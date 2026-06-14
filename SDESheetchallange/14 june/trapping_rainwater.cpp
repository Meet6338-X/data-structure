#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trapBrute(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int water = 0;
        
        for (int i = 0; i < n; i++) {
            int leftMax = 0;
            int rightMax = 0;
            
            for (int j = 0; j < i; j++) {
                leftMax = max(leftMax, height[j]);
            }
            
            for (int j = i + 1; j < n; j++) {
                rightMax = max(rightMax, height[j]);
            }
            
            int minMax = min(leftMax, rightMax);
            if (minMax > height[i]) {
                water += minMax - height[i];
            }
        }
        
        return water;
    }
    
    int trapBetter(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        int water = 0;
        for (int i = 0; i < n; i++) {
            int minMax = min(leftMax[i], rightMax[i]);
            water += max(0, minMax - height[i]);
        }
        
        return water;
    }
    
    int trapOptimal(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        int left = 0;
        int right = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        
        return water;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    
    Solution sol;
    
    cout << "Trap Water (Brute): " << sol.trapBrute(height) << endl;
    cout << "Trap Water (Better): " << sol.trapBetter(height) << endl;
    cout << "Trap Water (Optimal): " << sol.trapOptimal(height) << endl;
    
    return 0;
}