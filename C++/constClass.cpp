#include <iostream>
using namespace std;
class Debug
{
	public:
		constexpr Debug(bool b = true) : hw(b), io(b), other(b) { }
		constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) { }
		constexpr bool any() { return hw || io || other; }
		void set_io(bool b) { io = b; }
		void set_hw(bool h) { hw = h; }
		void set_other(bool b) { other = b; };
	private:
		 bool hw;
		 bool io;
		 bool other;
};

int main()
{
	Debug io_sub(false, true, false);
	if (io_sub.any())
		cerr << "Print appropriate error messages" << endl;
	Debug prod(false);
	prod.set_io(true);
	if (prod.any())
		cerr << "Print an error message" << endl;
	return 0;
}
