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
	clear();
}

template <class T>
void List<T>::clear()
{
	Node* sRunner = m_root;
	Node* fRunner = m_root->next();

	while (sRunner)
	{
		delete sRunner;
		sRunner = fRunner;
		fRunner = fRunner->next();
	}

	m_root = nullptr;
}

template <class T>
std::ostream& operator << (std::ostream& listOut, const List<T>& list)
{
	Node* runner = m_root->next();
	while (runner)
	{
		listOut << runner->elem() << " ";
		runner = runner->next;
	}

	return listOut;
}

template <class T>
std::istream& operator >> (std::istream& listIn, List<T>& list)
{
	if (m_root)
		clear();

	int len;
	listIn >> len;

	Node* runner = m_root;
	T elem;

	for (int i = 0; i < len; ++i)
	{
		listIn >> elem;
		runner->setNext(elem);
		runner = runner->next();
	}

	return listIn;
}

template <class T>
List<T>::Node* List<T>::find(T elem)
{
	Node* runner = m_root->next();

	while (runner)
	{
		if (runner->elem() == elem)
			return runner;
	}

	return runner;
}

template <class T>
void List<T>::pushFront(const T elem)
{
	Node* next = m_root->next();
	m_root->setNext(elem);
	m_roor->next()->setNext(next);
}

template <class T>
void List<T>::popBack()
{
	if (m_root == nullptr)
		throw logic_error("trying to delete from an empty list");

	Node* runner = m_root;

	while (runner->next()->next())
		runner = runner->next();

	delete runner->next();
}

template <class T>
int List<T>::size() const
{
	int counter = 0;
	Node* runner = m_root;

	while (runner->next()) {
		counter++;
		runner = runner->next();
	}

	return counter;
}