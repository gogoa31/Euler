#include <iostream>
#include <deque>
using namespace std;
int main()
{
	deque<int>vec1;
	deque<int>vec2;
	vec1.push_front(1);
	int after=0,rem=0,total=0;
	int i;
	for (int count=1;count<=40;++count)
	{
		bool flag=true;
		if (vec1.size()!=0)//往vec2里放
		{
			i=vec1.size()-1;
			while(flag==true && vec1.size()!=0)//往vec2里放
			{	
				//i=vec1.size()-1;
				total=count*vec1[i]+rem;
				rem=0;
				if(total>9 && i>0)
				{
					after=total%10;
					vec2.push_front(after);
					rem=total/10;
				}
				else if(total<=9 && i>0)
				{
					vec2.push_front(total);
				}
				else if(i==0)
				{
					if (total>9)
					{
						after=total%10;
						vec2.push_front(after);
						rem=total/10;
						vec2.push_front(rem);
					}
					else
					{
						vec2.push_front(total);
					}
				}
				else if(i<0)
				{
					vec1.erase(vec1.begin(),vec1.end());
					flag=false;
				}
				--i;
			}
		}
		else//往vec1里放
		{
			i=vec2.size()-1;
			while (flag==true && vec2.size()!=0)//往vec1里放
			{
				total=count*vec2[i]+rem;
				rem=0;
				if(total>9 && i>0)
				{
					after=total%10;
					vec1.push_front(after);
					rem=total/10;
				}
				else if(total<=9 && i>0)
				{
					vec1.push_front(total);
				}
				else if (i==0)
				{
					if (total>9)
					{
						after=total%10;
						vec1.push_front(after);
						rem=total/10;
						vec1.push_front(rem);
					}
					else
					{
						vec1.push_front(total);
					}
				}
				else if(i<0)
				{
					vec2.erase(vec2.begin(),vec2.end());
					flag=false;
				}
				--i;
			}
		}
	}
	cout<<endl;
	if (vec1.size()>0)
	{
		//int sum=0;
		deque<int>::iterator it;
		for (it=vec1.begin();it!=vec1.end();++it)
		{
			cout<<*it;
		}
		//cout<<"  sum of 100! is: "<<sum<<endl;
	}
	else
	{
		//int sum=0;
		deque<int>::iterator it;
		for (it=vec2.begin();it!=vec2.end();++it)
		{
			cout<<*it;
		}
		//cout<<"  sum of 100! is: "<<sum<<endl;
	}
	cout<<endl;
	return 0;
}
