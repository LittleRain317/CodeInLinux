#include <iostream>
#include <string>
using namespace std;

int ctoh(int);

string escape(string const& s)
{
	int i, c, size=s.size();
	string s1;
	for (i=0; i<size; ++i) {
		c = s[i];
		if (c == '\\') {
			if (++i >= size)
				break;
			c = s[i];
			switch (c) {
			case '\\':
				s1.push_back(c); break;
			case 'a':
				s1.push_back(7); break;
			case 'b':
				s1.push_back(8); break;
			case 'e':
				s1.push_back(27); break;
			case 'f':
				s1.push_back(12); break;
			case 'n':
				s1.push_back(10); break;
			case 'r':
				s1.push_back(13); break;
			case 't':
				s1.push_back(9); break;
			case 'v':
				s1.push_back(11); break;
			case '\'':
				s1.push_back('\''); break;
			case '\"':
				s1.push_back('\"'); break;
			case 'x':
				i += 2;
				if (i >= s.size()) break;
				c = ctoh(s[i-1]);
				c = (c<<4) + ctoh(s[i]);
				s1.push_back(c); break;
			default:
				s1.push_back(c);
			}
		} else
			s1.push_back(c);
	}
	return s1;
}

int ctoh(int c)
{
	if (c <= '9')
		return c-'0';
	if (c <= 'F')
		return c-'A'+10;
	return c-'a'+10;
}
