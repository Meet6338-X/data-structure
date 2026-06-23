#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr = {2, 5, 1, 3, 0};
    int large = arr[0];
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i + 1] >= large)
        {
            large = arr[i + 1];
        }
    }
    cout << "largest : " << large;
}