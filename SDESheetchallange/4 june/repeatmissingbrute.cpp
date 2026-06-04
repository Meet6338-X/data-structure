#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int repeat = -1, miss = -1;

    for (int i = 1; i <= a.size(); i++)
    {
        int cnt = 0;

        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] == i)
            {
                cnt++;
            }
        }

        if (cnt == 2)
            repeat = i;
        else if (cnt == 0)
            miss = i;

        if (repeat != -1 && miss != -1)
            break;
    }

    return {repeat, miss};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 3};
    vector<int> result = findMissingRepeatingNumbers(a);
    cout << "Repeating: " << result[0] << ", Missing: " << result[1] << endl;
    return 0;
}