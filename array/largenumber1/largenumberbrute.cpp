#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> arr = {2, 5, 1, 3, 0};
    sort(arr.begin(), arr.end());
    cout << "largest = " << arr[arr.size() - 1];
}
