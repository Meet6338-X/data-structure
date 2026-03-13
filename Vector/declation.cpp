#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1(5, 20);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i];
    }
    vector<int> v2(v1);
    cout << endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i];
    }
}