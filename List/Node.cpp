#include "List.h"

template <class T>
List<T>::Node::Node()
{
	m_next = nullptr;
}

template <class T>
List<T>::Node::Node(const T elem)
{
	m_next = nullptr;
	m_elem = elem;
}

template <class T>
List<T>::Node* List<T>::Node::next()
{
	return m_next;
}


template <class T>
void List<T>::Node::setNext(Node* node)
{
	m_next = node;
}