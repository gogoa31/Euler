#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int>vec1;
	vector<int>vec2;
	vec1.push_front(1);
	int prev=1,after=0,rem=0,total=0;
	int i;
	for (int count=1;count<=6;++count)
	{
		bool flag=true;
		bool v1=true;
		bool v2=true;
		if (vec1.size()!=0)//往vec2里放
		{
			i=vec1.size()-1;
			while(flag==true && vec1.size()!=0)//往vec2里放
			{	
				//i=vec1.size()-1;
				total=count*vec1[i]+rem;
				//rem=0;
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
					vec1.erase();
					flag=false;
				}
				--i;
			}
		}
		else
		{
			i=vec2.size()-1;
			while (flag==true && vec2.size()!=0)//往vec1里放
			{
				total=count*vec2[i]+rem;
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
					vec2.erase();
					flag=false;
				}
				++i;
			}
		}
}