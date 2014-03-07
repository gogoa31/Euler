#include <iostream>
using namespace std;
int main()
{
	unsigned int a;
	unsigned int b;
	unsigned int c;
	bool flag=false;
	while (flag!=true)
		for ( c=0;c<1000;++c)
			for (b=0;b<c;++b)
				for (a=0;a<b;++a)
					if (a*a+b*b==c*c && a+b+c==1000)
					{
						cout<<"a: "<<a<<'\n'<<"b: "<<b<<'\n'<<"c: "<<c<<endl;
						flag=true;
					}
	return 0;
}