#include<iostream>
using namespace std;
int main()
{
    int x;
    cin>>x;
	int rev=0;
        int last=0;
        while(x>0)
        {
            last=x%10;
            rev = (rev * 10)+last;
            x=x/10;
        }
        cout<<rev;
}