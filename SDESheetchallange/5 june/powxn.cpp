#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        long long nn = n;

        if (nn < 0)
        {
            nn = -1 * nn;
        }

        while (nn)
        {
            if (nn % 2)
            {
                ans = ans * x;
                nn = nn - 1;
            }
            else
            {
                x = x * x;
                nn = nn / 2;
            }
        }

        if (n < 0)
        {
            ans = 1.0 / ans;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.myPow(2.00000, 10) << endl;  // Expected: 1024.0
    cout << s.myPow(2.10000, 3) << endl;   // Expected: 9.261
    cout << s.myPow(2.00000, -2) << endl;  // Expected: 0.25
    return 0;
}