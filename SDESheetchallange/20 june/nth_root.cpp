#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double nthRootBrute(int n, int m) {
        double ans = 1.0;
        for (long long i = 1; i <= m; i++) {
            long long pow = 1;
            for (int j = 0; j < n; j++) {
                pow *= i;
            }
            if (pow == m) {
                return (double)i;
            }
            if (pow > m) {
                return (double)(i - 1);
            }
        }
        return (double)ans;
    }
    
    double nthRootBetter(int n, int m) {
        double low = 1.0;
        double high = m;
        double eps = 1e-6;
        
        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            
            if (calculatePower(mid, n) < m) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
    
    double nthRootOptimal(int n, int m) {
        return nthRootBetter(n, m);
    }

private:
    double calculatePower(double num, int n) {
        double result = 1.0;
        for (int i = 0; i < n; i++) {
            result *= num;
        }
        return result;
    }
};

int main() {
    int n = 3;
    int m = 27;
    
    Solution sol;
    
    cout << "Nth Root (Brute): " << sol.nthRootBrute(n, m) << endl;
    cout << "Nth Root (Better): " << sol.nthRootBetter(n, m) << endl;
    cout << "Nth Root (Optimal): " << sol.nthRootOptimal(n, m) << endl;
    
    return 0;
}