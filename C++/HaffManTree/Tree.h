#ifndef TREE_H_
#define TREE_H_

typedef class Tree Node;
typedef Node * pNode;

class Tree
{
	private:
		pNode m_pParent{nullptr};
		pNode m_pLeftChild{nullptr};
		pNode m_pRightChild{nullptr};
		char m_word{'\0'};
	public:
		void SetParent(pNode parent);
		void SetLeftChild(pNode leftChild);
		void SetRightChild(pNode rightChild);
		void SetWord(char word);
};
#endif
