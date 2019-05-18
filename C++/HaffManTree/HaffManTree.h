#ifndef HAFFMANTREE_H_
#define HAFFMANTREE_H_

#include <map>
#include <string>

using std::map;
using std::string;

class Tree;

class HaffManTree
{
	private:
		string m_source;
		string m_result;
		Tree * m_root{nullptr};
		map<char, unsigned> everyChar;
	public:
		void Code();
		void Decode();
		void ChangeResult();
		void ProceSource();
		void SetSource(string source);
		bool isExist(char word);
};
#endif
