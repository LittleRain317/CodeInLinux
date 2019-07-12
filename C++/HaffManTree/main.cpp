#include <iostream>
#include "HaffManTree.h"
int main(void)
{
	string txt;
	std::cin >> txt;
	HaffManTree tree;
	tree.SetSource(txt);
	tree.ProceSource();
	return 0;	
}
