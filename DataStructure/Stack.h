#pragma once
#include "Node.h"

template<typename T>
class Stack
{
public:
	Stack();
	~Stack();
	void Push(Node<T>*);
	Node<T> * Pop();
	bool NotEmpty();
private:
	Node<Node<T>> * m_pHead;
	Node<Node<T>> * m_pTail;
	Node<T> * m_pTempDataNode;
	int m_ElemCount;
};

template<typename T>
Stack<T>::Stack()
{
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_pTempDataNode = nullptr;
	m_ElemCount = 0;
}

template<typename T>
Stack<T>::~Stack()
{
}

template<typename T>
void Stack<T>::Push(Node<T> * obj)
{
	cout << "Push" << endl;
	if (obj)
	{
		Node<Node<T>> * new_node = new Node<Node<T>>(obj);
		if (m_ElemCount == 0)
		{
			m_pHead = new_node;
		}
		else
		{
			new_node->m_pPrev = m_pTail;
			m_pTail->m_pNext = new_node;
		}
		m_pTail = new_node;
		m_ElemCount++;
	}
}

template <typename T>
Node<T> * Stack<T>::Pop()
{
	cout << "Pop" << endl;
	m_pTempDataNode = nullptr;
	if (m_ElemCount > 0 && m_pTail)
	{
		m_pTempDataNode = m_pTail->m_pElem;
		if (m_ElemCount == 1)
		{
			cout << "Poping the last node" << endl;
		}
		else
		{
			m_pTail = m_pTail->m_pPrev;
			delete m_pTail->m_pNext;
			m_pTail->m_pNext = nullptr;
		}
	}
	this->m_ElemCount--;
	return m_pTempDataNode;
}

template <typename T>
bool Stack<T>::NotEmpty()
{
	return m_ElemCount == 0 ? false : true;
}