// majority element's greater than n/2
#include <iostream>
using namespace std;
int main()
{
    int arr[7] = {7, 2, 2, 8, 2, 3, 2};
    int n = 7, temp = 0, cnt = 0, item = 0;
    for (int i = 0; i < n; i++)
    {
        temp = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (temp == arr[j])
            {
                cnt++;
                if (cnt > n / 2)
                {
                    item = temp;
                    break;
                }
            }
        }
        cnt = 0;
    }
    cout << item;
    return 0;
}