#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int matrixMedianBrute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> flat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                flat.push_back(matrix[i][j]);
            }
        }
        
        for (int i = 0; i < flat.size() - 1; i++) {
            for (int j = i + 1; j < flat.size(); j++) {
                if (flat[i] > flat[j]) {
                    swap(flat[i], flat[j]);
                }
            }
        }
        
        int mid = (n * m) / 2;
        return flat[mid];
    }
    
    int matrixMedianBetter(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 1;
        int high = 1000000001;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                count += upperBound(matrix[i], mid);
            }
            
            if (count <= (n * m) / 2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return low;
    }
    
    int matrixMedianOptimal(vector<vector<int>>& matrix) {
        return matrixMedianBetter(matrix);
    }

private:
    int upperBound(vector<int>& arr, int x) {
        int low = 0;
        int high = arr.size();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= x) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    
    Solution sol;
    
    cout << "Matrix Median (Brute): " << sol.matrixMedianBrute(matrix) << endl;
    cout << "Matrix Median (Better): " << sol.matrixMedianBetter(matrix) << endl;
    cout << "Matrix Median (Optimal): " << sol.matrixMedianOptimal(matrix) << endl;
    
    return 0;
}