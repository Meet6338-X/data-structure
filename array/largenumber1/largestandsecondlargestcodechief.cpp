#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int mx = INT_MIN;
        int secondMx = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;

            if (x > mx)
            {
                secondMx = mx;
                mx = x;
            }
            else if (x > secondMx && x != mx)
            {
                secondMx = x;
            }
        }

        cout << mx + secondMx << '\n';
    }
}