// sort array 0  1 , 2
#include <iostream>
using namespace std;
int main()
{
    int n = 8;
    int arr[n] = {2, 0, 1, 2, 0, 1, 0, 2};
    int cut0 = 0, cut1 = 0, cut2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            cut0++;
        }
        else if (arr[i] == 1)
        {
            cut1++;
        }
        else if (arr[i] == 2)
        {
            cut2++;
        }
        else
        {
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (cut0 > 0)
        {
            arr[i] = 0;
            cut0--;
        }
        else if (cut1 > 0 && cut0 == 0)
        {
            arr[i] = 1;
            cut1--;
        }
        else if (cut2 > 0 && cut1 == 0)
        {
            arr[i] = 2;
            cut2--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}