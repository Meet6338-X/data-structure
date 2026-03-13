#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    int count = 0;
    cout << "Enter two number's : ";
    cin >> n1;
    cin >> n2;
    int max = (n1 > n2 ? n1 : n2);
    int arr1[max], arr2[max];
    for (int i = 0; i < max; i++)
    {
        arr1[i] = 0;
        arr2[i] = 0;
    }

    for (int i = 1; i <= n1; i++)
    {
        if (n1 % i == 0)
        {
            arr1[count] = i;
            count++;
            cout << i << ",";
        }
    }
    cout << endl;
    count = 0;
    for (int i = 1; i <= n2; i++)
    {
        if (n2 % i == 0)
        {
            arr2[count] = i;
            count++;
            cout << i << ",";
        }
    }
    cout << endl;

    int gdc;
    int flag = 0;
    for (int i = max; i >= 0; i--)
    {
        if (flag == 1)
        {
            break;
        }
        for (int j = max; j >= 0; j--)
        {
            if (flag == 1)
            {
                break;
            }
            if (arr1[i] == arr2[j] && arr1[i] != 0)
            {
                gdc = arr1[i];
                cout << gdc;
                flag = 1;
                break;
            }
        }
    }
    return 0;
}

// Better
// #include <iostream>
// #include <algorithm>

// using namespace std;

// int findGcd(int n1, int n2)
// {
//     // Iterate from the minimum of
//     // n1 and n2 down to 1
//     // Start from the minimum of n1 and n2
//     // because the GCD cannot
//     // exceed the smaller number

//     for (int i = min(n1, n2); i > 0; i--)
//     {
//         // Check if i is a common
//         // factor of both n1 and n2
//         if (n1 % i == 0 && n2 % i == 0)
//         {
//             // If i is a common factor,
//             // return it as the GCD
//             return i;
//         }
//     }
//     // If no common factors are found,
//     // return 1 (as 1 is always a
//     // divisor of any number)
//     return 1;
// }

// int main()
// {
//     int n1 = 20, n2 = 15;

//     // Find the GCD of n1 and n2
//     int gcd = findGcd(n1, n2);

//     cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }

// optimal
//  #include <iostream>
//  #include <algorithm>

// using namespace std;

// int findGcd(int a, int b)
// {
//     // Continue loop as long as both
//     // a and b are greater than 0
//     while (a > 0 && b > 0)
//     {
//         // If a is greater than b,
//         // subtract b from a and update a
//         if (a > b)
//         {
//             // Update a to the remainder
//             // of a divided by b
//             a = a % b;
//         }
//         // If b is greater than or equal
//         // to a, subtract a from b and update b
//         else
//         {
//             // Update b to the remainder
//             // of b divided by a
//             b = b % a;
//         }
//     }
//     // Check if a becomes 0,
//     // if so, return b as the GCD
//     if (a == 0)
//     {
//         return b;
//     }
//     // If a is not 0,
//     // return a as the GCD
//     return a;
// }

// int main()
// {
//     int n1 = 20, n2 = 15;

//     // Find the GCD of n1 and n2
//     int gcd = findGcd(n1, n2);

//     cout << "GCD of " << n1 << " and " << n2 << " is: " << gcd << endl;

//     return 0;
// }
