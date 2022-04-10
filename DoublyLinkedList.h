#ifndef Double_
#define Double_
#include <iostream>
#include <string>
template <class T>
class DoubleNode
{
public:
	T data;
	DoubleNode<T> *next, *prev;

	DoubleNode()
	{
		next = prev = nullptr;
	}
	~DoubleNode() {}
};
template <class T>
class DoublyLinkedList
{
public:
	// constructor
	DoublyLinkedList();
	//destructor
	~DoublyLinkedList();

	// basic method
	int Length() const;
	DoublyLinkedList<T>& Delete(int k, T& x);
	bool Find(int k, T& x) const;
	DoublyLinkedList<T>& Insert(int k, const T& x);
	void Output(std::ostream& out) const;
    int Search(const T& x) const;

	// my method
	bool Sorted();
private:
	DoubleNode<T> *leftEnd, *rightEnd;
	int length;

	// methods needed
	bool isEmpty();
	void checkIndex(int index);
};

#endif
