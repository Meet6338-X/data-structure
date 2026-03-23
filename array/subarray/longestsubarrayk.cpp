#include <iostream>
using namespace std;
int main()
{
    cout << "Enter array size : ";
    int n, ele, k, sum = 0, count = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr[i] = ele;
    }
    cout << "Enter k element : ";
    cin >> k;
    for (int j = 0; j < n; j++)
    {
        if (sum == k)
        {
            break;
        }
        for (int i = j; i < n; i++)
        {
            sum += arr[i];
            count++;
            if (sum == k)
            {
                break;
            }
        }
    }

    cout << "Subarray : ";
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " , ";
    }
}
