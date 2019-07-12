/* 一元一次方程解法:
 * 将等号两边式子分别计算
 * 先将式子进行规格化（即将乘法24a × 4 转化为4 × 24a)
 * 其次将数值存放在列表中同时存放每项最后一位数码
 * 再进行乘法分析
 * 未知数系数分析
 * 最后将列表中剩余的数字进行求和
 */
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <cstring>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;

string standardize(const string & expression, bool flag)
{

	//进行规格化处理
	char * myExpression = new char[expression.length() + 1];
	memset(myExpression, 0, sizeof(myExpression));
	int my_index = 0;
	for (int index = 0; index <= expression.length(); ++index)
	{
		//先找到乘法
		if (expression[index] == '*')
		{
			//判断前面是否带有未知数
			//越界处理
			if (index - 1 < 0)
				;
			else
			{
				if (expression[index - 1] >= 'a' && expression[index - 1] <= 'z')
				{
					//33 * 24a*4+  4*24a
					char * temp = new char[expression.length()];
					char * front_temp = new char[expression.length()];
					int temp_index = 0;
					memset(temp, 0, sizeof(temp));
					memset(front_temp, 0, sizeof(front_temp));
					int next = 0;
					for (next = index + 1; next <= expression.length() && 
							expression[next] >= '0' && expression[next] <= '9'; ++next)
					{
						temp[temp_index++] = expression[next];
					}
					int fr_temp_index = 0;
					//拷贝前面未知数
					int front = 0;
					for (front = index - 1; front >= 0 && 
							(expression[front] >= '0' && expression[front] <= '9' || 
							 (expression[front] >= 'a' && expression[front] <= 'z')); --front)
					{
						front_temp[fr_temp_index++] = expression[front];
					}
					//next = 0;
					//front = 0;
					//strcat(myExpression, temp);
					int sub_count = 0;
					//回退
					while (true)
					{
						if (sub_count == strlen(front_temp))
							break;
						my_index--;
						sub_count++;
					}
				//	cout << my_index ;
					next = 0;
					front = 0;
					for (; temp[next] != '\0'; ++next)
					{
						myExpression[my_index++] = temp[next];
					}
					myExpression[my_index++] = '*';
					for (front = strlen(front_temp) - 1; front >= 0; --front)
					{
						myExpression[my_index++] = front_temp[front];
					}
					//strcat(myExpression, front_temp);
				//	cout << "temp:" << temp;
				//	cout << "\nfront_temp" << front_temp;
				//	cout << std::endl;
				//	cout << myExpression;
					index = strlen(myExpression) - 1;
					flag = true;
			//		cout <<"index:" << index << " " << "char:" << expression[index] << endl;
			//		cout << "my:" << myExpression << endl;
			//		cout << "my_index:" << my_index << endl;
				}
				else
				{
					myExpression[my_index++] = expression[index];		
				}
			}	
		}
		else
		{
			myExpression[my_index++] = expression[index];
		}
			
	}
	if (flag)
	{
	//	cout << "调用后的结果:" << myExpression << endl;
		flag = false;
		return standardize(myExpression, flag);
	}
	else
		return expression;
}
int main(void)
{
	map<int, int> number;
	string expression = "NULL";
	cin >> expression;
	string leftExpression = "";
	string rightExpression = "";
	leftExpression = expression.substr(0, expression.find("="));
	rightExpression = expression.substr(expression.find("=") + 1, expression.length());
	cout << "左边: " << leftExpression << endl;
	cout << "右边: " << rightExpression << endl;
	cout << standardize(leftExpression, false);
        cout<< endl;
	cout << standardize(rightExpression, false);
	cout<< endl;
	return 0;
}
