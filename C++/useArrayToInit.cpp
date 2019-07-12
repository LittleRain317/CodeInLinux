#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main(void)
{
	int arr[10] = {1, 2, 3, 4, 5};
	vector<int> v(begin(arr), end(arr));
	for (const auto it : v)
		cout << it << endl;
	return 0;
}
