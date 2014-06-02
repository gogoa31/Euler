#include <iostream>
using namespace std;
int main()
{
	int n;
	int maxN=0;
	freopen("plain_text","r",stdin);//freopen属于标准库函数，page 270,这个plain_text要和本文件保存于同一文件夹
	while(cin>>n)
	{
		if(maxN<n)
		{
			maxN=n;
		}
	}
	cout<<maxN<<endl;
	return 0;
}