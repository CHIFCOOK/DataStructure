#pragma once
#include "Node.h"


template <class T>
class DoublyLinkList
{
public:
	DoublyLinkList();
	~DoublyLinkList();
	void AddBack(T * p_elem);
	bool AddByIndex(int m_nIndex, T * elem);
	bool Traversal(bool select);
	bool DeleteByIndex(int m_nIndex);
	bool ClearAll();
	Node<T>* FindByIndex(int m_nIndex);
	Node<T>* FindByData(T*);
private:
	int m_ElemCount;
	Node<T>* m_pHead;
	Node<T>* m_pTail;
	Node<T>* m_pTemp;
	Node<T>** m_ppIndirect;
};

template <class T>
DoublyLinkList<T>::DoublyLinkList()
{
	m_pTemp = nullptr;
	m_pHead = new Node<T>(nullptr, nullptr, nullptr);
	m_pTail = m_pHead;
	m_ElemCount = 0;
}

template<class T>
inline void DoublyLinkList<T>::AddBack(T * p_elem)
{
	cout << "AddBack " << p_elem << endl;
	Node<T> * new_node = new Node<T>(p_elem, m_pTail, nullptr);
	if (new_node)
	{
		m_pTail->m_pNext = new_node;
		m_pTail = new_node;
		new_node->m_nIndex = ++m_ElemCount;
		cout << "Done!" << endl;
	}

}

template<class T>
inline bool DoublyLinkList<T>::AddByIndex(int m_nIndex, T * elem)
{
	cout << "AddByIndex " << m_nIndex << ":" << elem << endl;
	if (!FindByIndex(m_nIndex))
		return false;

	m_pTemp = m_pTail;
	for (int i = m_ElemCount; i >= m_nIndex; i--)
	{
		m_pTemp->m_nIndex++;
		m_pTemp = m_pTemp->m_pPrev;
	}

	//m_pTemp = (*m_ppIndirect)->m_pNext;
	//Node<T> * new_node = new Node<T>(elem, *m_ppIndirect, m_pTemp);
	//new_node->m_nIndex = m_nIndex;
	//(*m_ppIndirect)->m_pNext = new_node;
	//if (m_pTemp)
	//	m_pTemp->m_pPrev = new_node;
	//else
	//	m_pTail = new_node;

	m_pTemp = (*m_ppIndirect)->m_pPrev;
	Node<T> * new_node = new Node<T>(elem, m_pTemp, *m_ppIndirect);
	new_node->m_nIndex = m_nIndex;

	(*m_ppIndirect)->m_pPrev = new_node;
	if (m_pTemp)
		m_pTemp->m_pNext = new_node;
	else
		m_pHead = new_node;

	return true;
}

template<class T>
inline bool DoublyLinkList<T>::ClearAll()
{
	if (m_ElemCount == 0)return false;

	m_pTail = m_pHead;
	m_pHead = m_pHead->m_pNext;
	do
	{
		m_pTemp = m_pHead->m_pNext;
		delete m_pHead;
		m_pHead = m_pTemp;
		m_ElemCount--;
	} while (m_pTemp);
	m_pHead = m_pTail;

	cout << "clear" << endl;
	return true;
}

template<class T>
inline Node<T>* DoublyLinkList<T>::FindByIndex(int index)
{
	if (index > m_ElemCount || index < 0)
		return nullptr;

	m_ppIndirect = &m_pHead;
	while (index != (*m_ppIndirect)->m_nIndex)
		m_ppIndirect = &(*m_ppIndirect)->m_pNext;
	return *m_ppIndirect;
}

template<class T>
inline Node<T>* DoublyLinkList<T>::FindByData(T * data)
{
	Node<T> * ret = nullptr;
	if (data)
	{
		m_ppIndirect = &(m_pHead->m_pNext);
		while (*data != *((*m_ppIndirect)->m_pElem))
			m_ppIndirect = &(*m_ppIndirect)->m_pNext;
		ret = *m_ppIndirect;
	}
	return ret;
}

template <class T>
DoublyLinkList<T>::~DoublyLinkList()
{
	ClearAll();
	m_pHead = nullptr;
	m_pTail = nullptr;
	m_pTemp = nullptr;
	m_ppIndirect = nullptr;
}

template<class T>
inline bool DoublyLinkList<T>::Traversal(bool select)
{
	if (m_ElemCount == 0)
		return false;

	if (select)
	{
		m_pTemp = m_pHead->m_pNext;
		while (m_pTemp)
		{
			cout << m_pTemp << endl;
			m_pTemp = m_pTemp->m_pNext;
		}
	}
	else
	{
		m_pTemp = m_pTail;
		while (m_pTemp->m_pPrev)
		{
			cout << m_pTemp << endl;
			m_pTemp = m_pTemp->m_pPrev;
		}
	}
	return true;
}

template<class T>
inline bool DoublyLinkList<T>::DeleteByIndex(int index)
{
	if (!m_ppIndirect = FindByIndex(index))return false;
	m_pTemp = (*m_ppIndirect)->m_pPrev;
	*m_ppIndirect = (*m_ppIndirect)->m_pNext;
	*m_ppIndirect ? (*m_ppIndirect)->m_pPrev = m_pTemp : m_pTail = m_pTemp;
	return true;
}