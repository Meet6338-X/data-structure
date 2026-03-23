#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
// LC : 7 Reverse number
class Solution
{
public:
    int reverse(int x)
    {
        int flag = 0, rev = 0, last = 0;
        if (x > 0)
        {
            flag = 1;
        }
        x = x * x;
        x = pow(x, 0.5);
        while (x != 0)
        {
            last = x % 10;
            rev = (rev * 10) + last;
            x = x / 10;
        }
        if (flag == 0)
        {
            rev = -1 * rev;
        }
        return rev;
    }
};

// class Solution
// {
// public:
//     int reverse(int x)
//     {
//         int rev = 0;
//         while (x)
//         {
//             if (rev > INT_MAX / 10 || rev < INT_MIN / 10)
//             {
//                 return 0;
//             }
// [-2^31, 2^31 - 1]  2^31 = 2147483648 = 10 digits
//             rev = rev * 10 + x % 10;
//             x = x / 10;
//         }
//         return rev;
//     }
// };