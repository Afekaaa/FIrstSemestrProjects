#include "List.h"

template <class T>
List<T>::List(const TemplateArray<T>& arr, int len)
{
	Node* runner = m_root;

	for (int i = 0; i < len; ++i)
	{
		runner->setNext(arr[i]);
		runner = runner->next();
	}
}


template<class T>
List<T>::List(const List& other)
{
	Node* runner = m_root;
	Node* otherRunner = other.m_root();

	while (otherRunner->next())
	{
		runner->setNext(otherRunner->next()->elem());
		runner = runner->next();
		otherRunner = otherRunner->next();
	}
}

template <class T>
List<T>::~List()
{
	Node* sRunner = m_root;
	Node* fRunner = m_root->next();

	while (sRunner)
	{
		delete sRunner;
		sRunner = fRunner;
		fRunner = fRunner->next();
	}
}
