#pragma once
#include "Stack.h"

template<typename T>
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	Node<T> * InsertNode(T*);
	Node<T> * FindNode(T*);
	void MiddleOrder();
	void RemoveNode(T*);
private:
	Node<T> * m_BstNoneRec(Node<T>*, Stack<T> *);
	int m_ElemCount;
	Node<T> * m_pRoot;
	Node<T> * m_pTemp;
};
template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_pRoot = NULL;
	m_pTemp = NULL;
	m_ElemCount = 0;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	delete m_pTemp;
	delete m_pRoot;
	m_pTemp = nullptr;
	m_pRoot = nullptr;
	m_ElemCount = 0;
}

template<typename T>
inline Node<T>* BinarySearchTree<T>::InsertNode(T * obj)
{
	Node<T> * new_node = new Node<T>(obj, nullptr, nullptr, nullptr, nullptr);
	if (new_node)
	{
		cout << "inserting " << obj << endl;
		if (m_ElemCount == 0)
		{
			m_pRoot = new_node;
		}
		else
		{
			m_pTemp = m_pRoot;
			while (true)
			{
				if (*obj < *(m_pTemp->m_pElem))
				{
					if (m_pTemp->m_pLeft == nullptr)
					{
						new_node->m_pPrev = m_pTemp;
						m_pTemp->m_pLeft = new_node;
						break;
					}
					m_pTemp = m_pTemp->m_pLeft;
				}
				else
				{
					if (m_pTemp->m_pRight == nullptr)
					{
						new_node->m_pPrev = m_pTemp;
						m_pTemp->m_pRight = new_node;
						break;
					}
					m_pTemp = m_pTemp->m_pRight;
				}
			}

		}
		new_node->m_nIndex = ++m_ElemCount;;
		cout << "insert done!" << endl;
	}
	else
	{
		cout << "Can't creat a new node!" << endl;
	}
	return new_node;
}

// Non-rec core code
template<typename T>
Node<T> * BinarySearchTree<T>::m_BstNoneRec(Node<T> * temp, Stack<T> * S)
{
	Node<T> * ret = nullptr;
	if (m_ElemCount > 0)
	{
		m_pTemp = temp;
		if (m_pTemp || S->NotEmpty())
		{
			while (m_pTemp)
			{
				S->Push(m_pTemp);
				m_pTemp = m_pTemp->m_pLeft;
			}
			if (S->NotEmpty())
			{
				m_pTemp = S->Pop();
				ret = m_pTemp;
				m_pTemp = m_pTemp->m_pRight;
			}
		}
	}
	return ret;
}

template<typename T>
Node<T> * BinarySearchTree<T>::FindNode(T* data)
{
	Stack<T>  S;
	Node<T> * ret = nullptr;
	m_pTemp = m_pRoot;
	cout << "Finding " << data << endl;
	while (ret = m_BstNoneRec(m_pTemp, &S))
	{
		if (*(ret->m_pElem) == *data)
		{
			cout << "Found!!:" << ret << endl;
			break;
		}
	}
	return ret;
}

template<typename T>
void  BinarySearchTree<T>::MiddleOrder()
{
	cout << "-----Traversal-----" << endl;
	Node<T> * ret = nullptr;
	Stack<T> S;
	m_pTemp = m_pRoot;
	while (ret = m_BstNoneRec(m_pTemp, &S))
	{
		cout << ret << endl;
	}
	cout << "-----Finish!-----" << endl;

}

template<typename T>
void BinarySearchTree<T>::RemoveNode(T* data)
{
	cout << "---Removing---" << endl;
	Node<T> * des = nullptr;
	if (des = FindNode(data))
	{
		// Is a root node
		if (des->m_pPrev == nullptr)
		{
			// Only has left subtree
			if (des->m_pLeft && des->m_pRight == nullptr)
			{
				m_pTemp = des;
				des = des->m_pLeft;
				delete m_pTemp;
				m_pTemp = nullptr;
			}
			// Only has right subtree
			else if (des->m_pLeft == nullptr && des->m_pRight)
			{
				m_pTemp = des;
				des = des->m_pRight;
				delete m_pTemp;
				m_pTemp = nullptr;
			}
			// Has left and right subtree
			else if (des->m_pLeft && des->m_pRight)
			{
				m_pTemp = des;
				Node<T> * right_smallest = des->m_pRight;
				while (right_smallest->m_pLeft)
				{
					right_smallest = right_smallest->m_pLeft;
				}
				right_smallest->m_pLeft = des->m_pLeft;
				des = des->m_pRight;
				delete m_pTemp;
				m_pTemp = nullptr;
			}
			// Is a leaf node
			else if (!des->m_pLeft && !des->m_pRight)
			{
				des = nullptr;
			}
			// Upadate root
			m_pRoot = des;
			if (m_pRoot)
			{
				if (m_pRoot->m_pPrev)
				{
					m_pRoot->m_pPrev = nullptr;
				}
			}
		}
		// Is a left sub node
		else if (des == des->m_pPrev->m_pLeft)
		{
			// Only has left subtree
			if (des->m_pLeft && des->m_pRight == nullptr)
			{
				des->m_pPrev->m_pLeft = des->m_pLeft;
				delete des;
				des = nullptr;
			}
			// Only has right subtree
			else if (des->m_pLeft == nullptr && des->m_pRight)
			{
				des->m_pPrev->m_pLeft = des->m_pRight;
				delete des;
				des = nullptr;
			}
			// Has left and right subtree
			else if (des->m_pLeft && des->m_pRight)
			{
				des->m_pPrev->m_pLeft = m_pTemp->m_pRight;
				Node<T> * right_smallest = des->m_pRight;
				while (right_smallest->m_pLeft)
				{
					right_smallest = right_smallest->m_pLeft;
				}
				right_smallest->m_pLeft = des->m_pLeft;
				delete des;
				des = nullptr;
			}
			// leaf
			else if (!des->m_pLeft && !des->m_pRight)
			{
				delete des;
				des = nullptr;
			}
		}
		// Is a right sub node
		else if (des == des->m_pPrev->m_pRight)
		{
			// Only has left subtree
			if (des->m_pLeft && des->m_pRight == nullptr)
			{
				des->m_pPrev->m_pRight = des->m_pLeft;
				delete des;
				des = nullptr;
			}
			// Only has right subtree
			else if (des->m_pLeft == nullptr && des->m_pRight)
			{
				des->m_pPrev->m_pRight = des->m_pRight;
				delete des;
				des = nullptr;
			}
			// Has left and right subtree
			else if (des->m_pLeft && des->m_pRight)
			{
				des->m_pPrev->m_pRight = m_pTemp->m_pRight;
				Node<T> * right_smallest = des->m_pRight;
				while (right_smallest->m_pLeft)
				{
					right_smallest = right_smallest->m_pLeft;
				}
				right_smallest->m_pLeft = des->m_pLeft;
				delete des;
				des = nullptr;
			}
			// leaf
			else if (!des->m_pLeft && !des->m_pRight)
			{
				delete des;
				des = nullptr;
			}
		}
	}
	cout << "---Removing Done!---" << endl;
}