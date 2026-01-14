// copy example of unordered map
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
    unordered_map<string, int> mp;

    mp["apple"] = 10;
    mp["banana"] = 20;

    cout << mp["banana"]; // 10
}