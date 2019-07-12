#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int main(void)
{
	vector<int> numList;
	int tempNumber = 0;
	while (cin >> tempNumber)
		numList.push_back(tempNumber);
	for (decltype(numList.size()) index = 0; index < numList.size(); ++index)
		if (index + 1 < numList.size())
		cout << numList[index] + numList[index + 1] << endl;
	return 0;
}
