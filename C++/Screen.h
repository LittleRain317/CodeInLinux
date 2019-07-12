#ifndef SCREEN_H_
#define SCREEN_H_

#include <string>
using std::string;
class Screen
{
	public:
		using pos = string::size_type;
	private:
		string m_contents = "";
		pos m_cursor = 0;
		pos m_height = 0;
		pos m_width = 0;
	public:
		Screen() = default;
		Screen(pos height, pos width) : m_height(height), m_width(width) { }
		Screen(pos height, pos width, char contents) : m_height(height), m_width(width), m_contents(height * width, contents) { }

};
#endif //end define SCREEN_H_
