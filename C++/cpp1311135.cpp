#include <iostream>
#include <string>
using std::string;
using namespace std;
class HasPtr
{
private:
		string * ps;
		int i;
public:
		HasPtr(const string & s = string()) : ps(new string(s)), i(0) { }
		HasPtr(const HasPtr & t) : ps(new string(*(t.ps))), i((t.ps)->size()) { cout << " kfd" << endl; }
		bool operator== (const HasPtr & t) const 
		{
			return t.ps == ps && t.i == i;
		}


		HasPtr& operator= (const HasPtr & t)
		{
			auto it = new string(*(t.ps));
			delete ps;
			ps = it;
			i = t.i;
			cout << "===" << endl;
			return *this;
		}
		~HasPtr()
		{
			delete ps;
			cout << " 洗狗: " << endl;
		}
		
};
int main()
{
	HasPtr h;
	HasPtr copy = h;
	HasPtr c;
	c = h;
	c = c;
	return 0;
}
