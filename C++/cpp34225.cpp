#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	vector<unsigned> scoreList(11, 0U);
	unsigned score = 0U;
	auto it = scoreList.begin();
	while (cin >> score)
	{
		it += score / 10;
		++(*it);
		it = scoreList.begin();
	}	
	for (auto it : scoreList)
		cout << it << endl;

	return 0;
}
