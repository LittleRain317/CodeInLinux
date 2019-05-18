#include <iostream>
#include <string>
#include <fstream>
#include <climits>
using namespace std;
int main()
{
//	abcdefghijklmnopqrstuvwxyz;
	//上头
//	bdfhi
	//
//	gjpqty
	ifstream ifile("test.txt");
	if (ifile.fail())
	{	
		cerr << "失败!" << endl;
		return -1;
	}string temp;
	int max = INT_MAX;
	string maxS;
	while (ifile >> temp)
	{
		if (temp.find_first_of("bdfhiqjpqty") == string::npos)
		{	max = temp.size();
			maxS = temp;
		}
	}
	cout << max << " " << maxS <<endl;
	return 0;
}
