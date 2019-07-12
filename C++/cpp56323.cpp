#include <iostream>
#include <type_traits>
#include <limits>
#include <stdexcept>
using std::cin;
using std::cout;
using std::exception;
using std::endl;
using std::runtime_error;
int main(void)
{
	double a = 0;
	double b = 0;
	cout << "请输入两个数:" << endl;
	while (true)
	{
		try {
			while (cin >> a >> b)
			{
				try {
					if (b != 0)	
					break;
				}	
				catch (exception exc) {
					cout << exc.what() << "是否继续?Y or N" << endl;
					char select = 0;
					cin >> select;
					if (!cin || 'N' == select)
						return 1;
				}
			}
			if (!cin)
				throw runtime_error("请输入数字!\n");
			else
				break;
		}
		catch (runtime_error err) {
			cout << err.what() << "是否继续?" << endl;
			cout << "a:" << a << " b:" << b << endl;
			cout << "fail:" << cin.fail() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),  '\n');
			cout << "fail:" << cin.fail() << endl;
			char select = 0;
			cin >> select;
			cout << "select:" << select << endl;
			if (!cin || select == 'N')
				return 1;
		}
	}
	cout <<"a=" << a << " b=" << b << endl;
	cout << a / b << endl;
	return 0;
}
