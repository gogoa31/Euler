/*欧拉第20题，用的deque来做，没有用array。网上的答案大多用的array
  我用了两个deque来记录数字 ，一个deque记录一次的digits,一次过后下一次用另一个deque记录
  另一个记录完了之后，就清除第二个deque,重新记录。
  代码写的有些繁杂冗长，条件过多。
  希望在未来可以改进一下
*/
#include <iostream>
#include <deque>
using namespace std;
int main()
{
	deque<int>vec1;
	deque<int>vec2;
	vec1.push_front(1);//让vec1有内容，以便开始20行的if语句
	int after=0,rem=0,total=0,special;
	int i;
	for (int count=1;count<=100;++count)
	{
		bool flag=true;
		if (vec1.size()!=0)//往vec2里放
		{
			i=vec1.size()-1;//用i来做计数器，从大往小计，即--i;
			while(flag==true)//往vec2里放
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
						bool mark=true;
						while (mark!=false)
						{
							special=0;
							if (rem>9)
							{
								special=rem%10;
								vec2.push_front(special);
								rem=rem/10;
							}
							else
							{
								vec2.push_front(rem);
								mark=false;
							}
						}
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
			while (flag==true)//往vec1里放
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
				else if (i==0)//当i为0的时候比较tricky,刚开始没有考虑rem的值过大的问题
				{//一味的把rem当做数填进deque里，导致后来80！以后就开始溢出，连使用long long都是溢的
					if (total>9)
					{
						after=total%10;
						vec1.push_front(after);
						rem=total/10;
						bool jihao=true;
						while (jihao!=false)
						{
							special=0;
							if(rem>9)
							{
								special=rem%10;
								vec1.push_front(special);
								rem=rem/10;
							}
							else
							{
								vec1.push_front(rem);
								jihao=false;
							}
						}
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
	if (vec1.size()>0)//这里检查vec1、vec2谁有内容。有内容就把他们里面的digits相加
	{
		int sum=0;
		deque<int>::iterator it;
		for (it=vec1.begin();it!=vec1.end();++it)
		{
			sum=sum+(*it);
		}
		cout<<"  sum of 100! is: "<<sum<<endl;
	}
	else
	{
		int sum=0;
		deque<int>::iterator it;
		for (it=vec2.begin();it!=vec2.end();++it)
		{
			sum=sum+(*it);
		}
		cout<<"  sum of 100! is: "<<sum<<endl;
	}
	cout<<endl;
	return 0;
}
