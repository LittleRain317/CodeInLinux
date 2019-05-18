#include <iostream>
#include <string>
using namespace std;
class Date
{
	private:
		unsigned year = 0U;
		unsigned month = 0U;
		unsigned day = 0U;
	public:
		Date() = default;
		Date(string date)
		{
			if (date.find("/") != string::npos)
			{
				day = stoi(date);
				date.erase(date.find_first_of("1234567890"), to_string(day).size() + 1);
				month = stoi(date);
				date.erase(date.find_first_of("1234567890"), to_string(day).size() + 1);
				year = stoi(date);
			}
		}
		friend ostream& operator<<(ostream& os, const Date &date);
};
ostream & operator<<(ostream& os, const Date &date)
{
	os << date.year << " " << date.month << " " << date.day;
	return os;
}
int main()
{
	Date date("1/1/1990");
	cout << date << endl;
	return 0;
}
