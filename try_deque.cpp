#include <iostream>
#include <deque>
using namespace std;
int main()
{
	deque<int>a;
	for (int i=1;i<=1000000;++i)
	{
		a.push_front(i);
	}
	deque<int>::iterator it;
	for (it=a.begin();it!=a.end();++it)
	{
		cout<<*it;
	}
	return 0;
}