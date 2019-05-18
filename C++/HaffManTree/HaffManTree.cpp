#include <iostream>
using std::cout;
using std::endl;
#include "Tree.h"
#include "HaffManTree.h"


bool HaffManTree::isExist(char word)
{
	auto it =  everyChar.find(word);
	if (it == everyChar.end())
		return false;
	else
		return true;
}
void HaffManTree::ProceSource()
{
	unsigned countAppear = 1U;
	bool isFirstAppear = true;
/*	for (auto it : m_source)
	{
		if (isExist(it))
		{
			isFirstAppear = false;
			++countAppear;
		}
		else
		{
			if (isFirstAppear)
				everyChar.insert(map<char, unsigned>::value_type(it, 1U));
			else	
			{
				cout << it << " " << countAppear << endl;
				everyChar[it] = countAppear;
				countAppear = 1U;
			}
		}
	}
	cout << countAppear << endl;
	everyChar[m_source[m_source.size() - 1]] = countAppear;
*/
	for (decltype(m_source.size()) it = 0U; it < m_source.size(); ++it)
	{
		if (isExist(m_source[it]))
		{
			++countAppear;
			if (!it + 1 != m_source.size() && m_source[it + 1] != m_source[it])
			{
				everyChar[m_source[it]] = countAppear;
				countAppear = 1U;	
			}
		}
		else
		{	
			everyChar.insert(map<char, unsigned>::value_type(m_source[it], 1U));
		}
	}
	for (auto it : everyChar)
	{

	}
}

void HaffManTree::Code()
{

}

void HaffManTree::Decode()
{
}

void HaffManTree::SetSource(string source)
{
    m_source = source;
}

void HaffManTree::ChangeResult()
{
}
