#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::string;
using std::cout;
using std::endl;
int main(void)
{
	vector<int> v1;
	for (auto it : v1)
		cout << it << endl;
	cout << "第二个" << endl;
	vector<int> v2(10);
	for (auto it : v2)
		cout << it << endl;
	vector<int> v3(10, 42);
	for (auto it : v3)
		cout << it << endl;
	cout << "第三个" << endl;
	vector<int> v4{10};
	for (auto it : v4)
		cout << it << endl;
	cout << "第四个" << endl;
	vector<int> v5{10, 42};
	for (auto it : v5)
		cout << it << endl;
	cout << "第五个" << endl;
	vector<string> v6{10};
	for (auto it : v6)
		cout << it << endl;
	cout << "第六个" << endl;
	vector<string> v7{10, "hi"};
	for (auto it : v7)
		cout << it << endl;
	return 0;
}
