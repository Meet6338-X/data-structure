#include <iostream>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while(n>0)
    {
        count = count +1;
        n=n/10;
    }
    return count;
}

int main()
{
    int n;
    cout<<"Enter Number : ";
    cin>>n;
    cout<<countDigits(n);
}

//copy
// int countDigits(int n){
    // Initialize a variable 'cnt' to
    // store the count of digits.
    // int cnt = (int)(log10(n)+1);

    // The expression (int)(log10(n)+1)
    // calculates the number of digits in 'n'
    // and casts it to an integer.
    
    // Adding 1 to the result accounts
    // for the case when 'n' is a power of 10,
    // ensuring that the count is correct.
   
    // Finally, the result is cast
    // to an integer to ensure it is rounded
    // down to the nearest whole number.
    
    // Return the count of digits in 'n'.
    // return cnt;
// }
// Time complexity = O(log10N + 1)