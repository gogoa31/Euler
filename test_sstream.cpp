#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	stringstream ss;
	char ch1 = '3',ch2='4';
	int i;
	ss << ch1;
	ss >> i;
	cout << i <<endl;
	ss.clear();
	ss << ch2;
	ss >> i;
	cout << i <<endl;

	return 0;
}
