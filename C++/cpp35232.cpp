#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main(void)
{
	constexpr unsigned size = 10;
	int arr[size] = {0};
	for (size_t index = 0; index != size; ++index)
	{
		arr[index] = index;
	}
	int copy[size] = {0};
	for (size_t index = 0; index != size; ++index)
	{
		copy[index] = arr[index];
	}
	for (const auto it : copy)
	{
		cout << it << endl;
	}
	vector<size_t> numList(10);
	for (vector<int>::size_type index = 0U; index != numList.size(); ++index)
	{
		numList[index] = index;
	}
	for (const auto it : numList)
		cout << it << endl;
	return 0;
}
