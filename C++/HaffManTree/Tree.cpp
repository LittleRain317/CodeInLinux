#include "Tree.h"

void Tree::SetParent(pNode parent)
{
	m_pParent = parent;
}

void Tree::SetLeftChild(pNode leftChild)
{
	m_pLeftChild = leftChild;
}

void Tree::SetRightChild(pNode rightChild)
{
	m_pRightChild = rightChild;
}

void Tree::SetWord(char word)
{
	m_word = word;
}
