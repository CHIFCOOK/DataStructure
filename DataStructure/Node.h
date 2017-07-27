#pragma once
#include "iostream"
using namespace std;

template <typename T>
class List;

template <typename T>
class Node
{
public:
	friend List<T>;
	friend ostream &operator<< <>(ostream& out, const Node<T> * obj);
	Node(T * obj, Node * prev = nullptr, Node * next = nullptr, Node * left = nullptr, Node*right = nullptr);
	~Node();

	T* m_pElem;
	Node* m_pPrev;
	Node* m_pNext;
	//tree
	Node* m_pLeft;
	Node* m_pRight;
	int m_nIndex;
};


template <typename T>
ostream & operator<< <>(ostream & out, const Node<T> * obj)
{
	out << *(obj->m_pElem) << " index:" << obj->m_nIndex;
	return out;
}

template<typename T>
inline Node<T>::Node(T * obj, Node * prev = nullptr, Node * next = nullptr, Node * left = nullptr, Node*right = nullptr)
{
	cout << "Node()" << endl;
	m_pElem = obj;
	m_pPrev = prev;
	m_pNext = next;
	m_pLeft = left;
	m_pRight = right;
}



template<typename T>
inline Node<T>::~Node()
{
	cout << "~Node()" << endl;
}
