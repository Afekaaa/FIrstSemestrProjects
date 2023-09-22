#pragma once

#include "..\Array\TemplateArray.h"
#include <iostream>


template <class T>
class List
{
public:

	class Node
	{
	public:
		Node() = default;
		Node(const T elem);
		Node* next();
		void setNext();

	private:
		T elem;
		Node* next = nullptr;
	}; 

	List();
	List(const TemplateArray&<T> arr);
	List(const List& other);
	~List();

	friend std::ostream& operator << (std::ostream& listOut, const List& list);
	friend std::istream& operator >> (std::istream& listIn, List& list);

	Node* find(int elem);
	void pushFront(const T elem);
	void popBack();

	int size() const;

	List& operator = (const List& other);
	T& operator [] (int index);
	bool operator == (const List& other) const;
	bool operator != (const List& other) const;

private:
	Node* = nullptr;
};

