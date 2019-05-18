#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> vec{1, 2, 3, 4, 5, 6};
	auto iter = vec.begin();
	while (iter != vec.end())
	{	if (*iter % 2)
			iter = vec.insert(iter, *iter);
		++iter;
	}for (auto & it : vec)
		cout << it << endl;
	return 0;
}
