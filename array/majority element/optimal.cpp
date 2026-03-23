// Moore's Voting Algorithm
#include <iostream>
using namespace std;
int findMajorityElement(int arr[], int n)
{
    // find candidate
    int cnt = 0;
    int element;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt++;
            element = arr[i];
        }
        else if (arr[i] == element)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    // verfy
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            cnt1++;
    }

    if (cnt1 > (n / 2))
        return element;
    return -1;
}

int main()
{
    int arr[] = {2, 2, 1, 1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findMajorityElement(arr, n);

    if (result != -1)
    {
        cout << "Majority element is: " << result << endl;
    }
    else
    {
        cout << "No majority element exists" << endl;
    }

    return 0;
}