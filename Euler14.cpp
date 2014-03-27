#include <iostream>
#include <deque>
using namespace std;
int collatz(unsigned long);
int main()
{
	deque<unsigned long>a;
	a.push_back(1);
	a.push_back(2);//a{1,2}
	deque<unsigned long>b;
	for (unsigned long i=3;i<=1000000;++i)
	{
		if (i%2!=0)
		{
			b.push_back(i);//put the starting num. in the deque
			int j=collatz(i);
			b.push_back(j);//put the size of that starting num in the deque
			if (b[1]>a[1])
			{
				a[0]=b[0];
				a[1]=b[1];
				cout<<"replace a: "<<a[0]<<"  with b: "<<b[0]<<" i:  "<<i<<endl;
			}
			b.clear();
		}
	}
	cout<<"Biggest starting number is: "<<a[0]<<"the size is"<<a[1]<<endl;
	return 0;
}
int collatz(unsigned long n)//return the size of the current deque
{
	deque<unsigned long>a;
	bool flag=true;
	a.push_back(n);
	while(flag!=false)
	{
		if(n%2==0)
		{
			//cout<<"n是偶数前的值为： "<<n<<endl;
			n=n/2;
			a.push_back(n);
			//cout<<"        n是偶数时   "<<n<<endl;
		}
		else if (n==1 && a.size()==1)
		{
			n=3*n+1;
			a.push_back(n);
		}
		else if (n%2!=0 && n!=1)
		{
			//cout<<"n是奇数前的值为：  "<<n<<endl;
			n=3*n+1;
			a.push_back(n);
			//cout<<"          n是奇数时   "<<n<<endl;
		}
		else if (n==1 && a.size()!=1)
		{
			//a.push_back(n);
			//cout<<"     值为1，且值不是第一位,when dead"<<n<<endl;
			flag=false;
		}
	}
	return a.size();
}