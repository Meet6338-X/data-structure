// #include <iostream>
// using namespace std;
// int main()
// {
//     int n, count = 0;
//     cout << "Enter n to find all possible divisor : ";
//     cin >> n;
//     int arr[n];
//     for (int i = 1; i <= n; i++)
//     {
//         if (n % i == 0)
//         {
//             arr[count] = i;
//             count++;
//         }
//     }
//     cout << "divisor : ";
//     for (int i = 0; i < count; i++)
//     {
//         cout << arr[i] << " , ";
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "enter num : ";
    cin >> n;
    int arr[n];
    int count = 0;
    int temp;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[count] = i;
            count++;
            if (i != n / i)
            {
                temp = n / i;
                arr[count] = temp;
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " , ";
    }
    return 0;
}