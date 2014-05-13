#include <iostream>
#include <deque>
using namespace std;
int main()
{
	size_t i=1,sum=1,rem=0,sav=0;
	deque<size_t>deq1;
	deque<size_t>deq2;
	deq1.push_back(1);//deq1 ={1};
	while (i<=10)
	{
		i=i+1;
		cout<<"第一行"<<endl;
		cout<<"此时i 为 : "<<i<<endl;
		if (deq1.size()==0)//deq2 has digits now
		{
			cout<<"第二行"<<endl;
			for (size_t j=deq2.size()-1;;--j)
			{
				sum=0;
				sum=deq2[j]*2+rem;//sum * digits in deq2
				if (sum>9)
				{
					sav=sum%10;
					deq1.push_front(sav);
					cout<<"此时deq2有数字，当j="<<j<<"时，push了 sav 为"<<sav<<endl;
					rem=sum/10;
					if (j==0)//当读到第一个数字时，开始把rem按数字放入deque
					{
						if (rem>9)
						{
							size_t a=0;
							bool flag=true;
							while (flag!=false)
							{
								a=rem%10;//临时数，相当于rem
								deq1.push_front(a);
								rem=rem/10;
								a=0;
								if (rem<=9)
									flag=false;
							}

						}
						else
						{
							deq1.push_front(rem);
						}
					}
				}
				else
				{
					deq1.push_front(sum);
					cout<<"在第一阵队，放入sum"<<sum<<endl;
				}
			}
			deq2.erase(deq2.begin(),deq2.end());
		}
		else if (deq2.size()==0)//此时deq1里有数字
		{
			cout<<"滴二行"<<endl;
			for(size_t z=deq1.size()-1;;--z)
			{
				//cout<<"第三行"<<endl;
				sum=0;
				sum=deq1[z]*2+rem;
				if (sum>9)
				{
					sav=sum%10;
					deq2.push_front(sav);
					rem=sum/10;
					cout<<"deq1里有数字，此时z为"<<z<<"push了sav"<<endl;
					if (z==0)
					{
						if (rem>9)
						{
							size_t b=0;
							bool flag1=true;
							while (flag1!=false)
							{
								b=rem%10;
								deq2.push_front(b);
								rem=rem/10;
								b=0;
								if (rem<=9)
								{
									flag1=false;
								}
							}
						}
						else
						{
							deq2.push_front(rem);
						}
					}
				}
				else
				{
					deq2.push_front(sum);
					cout<<"在第二阵队放入sum"<<sum<<endl;
				}
			}
			deq1.erase(deq1.begin(),deq2.end());
			cout<<"执行了deq1 erase"<<endl;
		}
	}
	/*deque<size_t>::iterator it;
	if (deq1.size()!=0)
	{
		it=deq1.begin();
		cout<<"deq1 are: "<<endl;
		for (;it!=deq1.end();++it)
		{
			cout<<*it;
		}
	}
	else
	{
		it=deq2.begin();
		cout<<"deq2 are: "<<endl;
		for (;it!=deq2.end();++it)
		{
			cout<<*it;
		}
	}*/
	return 0;
}