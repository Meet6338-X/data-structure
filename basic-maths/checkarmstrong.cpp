#include <cmath>
#include <iostream>
using namespace std;
bool checkArmstrong(int n){
	int num =n;
	int count=0;
	int ld;
	int sum=0;
	while(num>0){
		count++;
		num = num/10; 
	}
	num =n;
	while(num>0)
	{
		ld = num%10;
		sum = sum+pow(ld,count);
		num = num/10;
	}
	if(n==sum){
		return true;
	}
	else{
		return false;
	}
}
