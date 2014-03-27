#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	ifstream num_file;
	ofstream ofile;
	char list[1000];
	int  num_list[1000];
	stringstream sstr;
	num_file.open("number.dat");
	ofile.open("test.log");
	for(int i=0;i<1000;i++)
	{
		num_file >> list[i];
		sstr << list[i]; // put the char "list[i]" into sstr
		sstr >> num_list[i]; 
		//Similar to "cin","sstr" automatically recognize num_list[i] is an integer and do the conversion
		sstr.clear();    // clear the content in sstr for next conversion
		ofile << num_list[i];
	}
	num_file.close();
	ofile.close();

	return 0;
}
