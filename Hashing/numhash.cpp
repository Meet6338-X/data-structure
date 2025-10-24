#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number array size : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " : ";
        cin >> arr[i];
    }

    // precompute:
    int hash[100000] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cout << "number of time we have to check : ";
    cin >> q;
    while (q--)
    {
        int number;
        cout << "enter number to hash : ";
        cin >> number;
        // fetching:
        cout << hash[number];
        cout << "time's " << endl;
    }
    return 0;
}