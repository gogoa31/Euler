#include <iostream>
#include <deque>
#include <cmath>
using namespace std;
int main()
{
	unsigned long int num;
	for (unsigned long int i=1;i<=10000000;++i)//use for loop to calculate triangle numbers and call count_divisors
	{
		int sum=0;
		num=i*(i+1)/2;
		//bool flag=false;
		for (unsigned long int div=1;div<=sqrt(num);++div)
		{
			if (num%div==0)
			{
				sum=sum+2;
			}
			if (sum>=500)
			{
				cout<<"Five hundreds divisors number: "<<num<<endl;
				return num;
			}

		}
	}
	return 0;
}