#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Enter String : ";
    cin >> s;

    // precompute:
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    int q;
    cout << "number of time we have to check : ";
    cin >> q;
    while (q--)
    {
        char c;
        cout << "enter character to hash : ";
        cin >> c;
        // fetch:
        cout << hash[c - 'a'];
        cout << "time's " << endl;
    }
    return 0;
}