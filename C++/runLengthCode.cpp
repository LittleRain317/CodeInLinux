/* 算法基本思路：逐个处理字符判断当前字符是否时第一个次出现，若是则拷贝
 * 其次判断是否和下一个字符相同，相同则该字码出现次数增加
 */

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string RunLengthCode(const string & txt);
int main(void)
{
	string txt;
	cin >> txt;
	cout << RunLengthCode(txt) << endl;
	return 0;
}
string RunLengthCode(const string & txt)
{
	string result;
	bool isFirstAppear = true;
	unsigned countAppear = 1U;
	stringstream ss;
	for (decltype(txt.size()) index = 0;
			index < txt.size(); ++index)
	{
		//判断是否是第一次出现
		if (isFirstAppear)
				result.append(1, txt[index]);
		//越界处理
		if ((index + 1) != txt.size())
		{	
			if (txt[index] == txt[index + 1])
			{
				isFirstAppear = false;
				++countAppear;
			}
			else
			{
				string temp;
				ss << countAppear;
				ss >> temp;
				ss.clear();
				result += temp;
				countAppear = 1U;
				isFirstAppear = true;
			}
		}
		else
		{
			string temp;
			ss << countAppear;
			ss >> temp;
			ss.clear();
			result += temp;
		}
	}
	return result;
}
