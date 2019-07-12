#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <stack>
using std::find;
using std::pair;
using std::make_pair;
using std::stack;
using std::map;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
int findMax(ListNode * head)
{
	if (nullptr == head)
		return 0;
	ListNode* pCurrent = head;
	int max = 0;
	while (pCurrent)
	{
		if (pCurrent->val > max)
			break;
		else
			pCurrent = pCurrent->next;
	}
	if (nullptr == pCurrent)
		return 0;
	else
		return pCurrent->val;
}

vector<int> nextLargerNodes(ListNode* head) 
{
        vector<int> result;
        if (nullptr == head)
                return result;
        ListNode * pCurrent = head;
        vector<pair<int, int>> myMap;
        stack<int> noMath;
        while (pCurrent)
        {
            myMap.push_back(make_pair(pCurrent->val, 0));//储存当前数据并且暂将下一个更大节点记为0
            while (!noMath.empty() && pCurrent->val > noMath.top())//不断匹配
            {
		find(myMap.begin(), myMap.end(), make_pair(noMath.top(), 0))->second = pCurrent->val;
                noMath.pop();
            }
            noMath.push(pCurrent->val);
            pCurrent = pCurrent->next;
        }
        for (const auto & it : myMap)
        {
            result.push_back(it.second);
        }
        return result;
}

int main()
{
	ListNode * head = new ListNode(2); 
	ListNode * newData;
	ListNode * pCurrent = head;
	int number = 0;
	while (cin >> number)
	{
		newData = new ListNode(number);
		pCurrent->next = newData;
		pCurrent = newData;
	}
	vector<int> result = nextLargerNodes(head);
	for (auto it : result)
		cout << it << " ";
	cout << endl;
	return 0;
}
