#include "DoublyLinkedList.h"


// constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	leftEnd = rightEnd = nullptr;
	length = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	// repeat and delete each node
	DoubleNode<T> *it = leftEnd, *temp;
	while (it != nullptr) {
		temp = it;
		it = it->next;
		delete temp;
	}

	leftEnd = rightEnd = nullptr;
	length = 0;
}

template<class T>
int DoublyLinkedList<T>::Length() const
{
	return length;
}

// A method that takes a starting point and a key to find and check if the key exists
template<class T>
bool DoublyLinkedList<T>::Find(int k, T & x) const
{
	if (k < 0 || k >= length)
		return false;

	// declare an repeat ptr
	DoubleNode<T> *it = leftEnd;

	//  until the position given
	for (int i = 0; i < k; i++) {
		it = it->next;
	}

	// save the value and declare success
	x = it->data;
	return true;
}

// A method that searches for a specific key and return its position
template<class T>
int DoublyLinkedList<T>::Search(const T & x) const
{
	// declare iterator ptr
	DoubleNode<T> *it = leftEnd;

	// iterate until you find it
	for (int i = 0; i < length; i++) {
		if (it->data == x)
			return i;
		it = it->next;
	}

	// otherwise
	return -1;
}

// A method that deletes an element with a given key
template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::Delete(int k, T & x)
{
	// iterator ptr
	DoubleNode<T> *it = leftEnd, *temp;

	// check index and that's not empty
	if (k < 0 || k >= length || isEmpty())
		return *this;


	// in case its the first element
	else if (k == 0) {
		temp = leftEnd;
		leftEnd = leftEnd->next;
		leftEnd->prev = nullptr;
	}

	// otherwise iterate untill the prev to the position given
	else {
		for (int i = 0; i < k - 1; i++) {
			it = it->next;
		}

		// in case it's the last element
		if (k == length - 1) {
			temp = rightEnd;
			rightEnd = it;
			rightEnd->next = nullptr;
		}

		// in case it's in between
		else {
			temp = it->next;
			it->next = temp->next;
			temp->next->prev = it;
		}
	}

	// delete the element and save its value
	x = temp->data;
	delete temp;
	length--;
	return *this;
}

// A methdod that inserts an element into agiven position
template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::Insert(int k, const T & x)
{
	// A method that check the index is valid
	checkIndex(k);

	// create a new node
	DoubleNode<T> *newNode = new DoubleNode<T>();
	newNode->data = x;

	// insert in case it's empty
	if (isEmpty()) {
		leftEnd = rightEnd = newNode;
	}

	// insert in case at the beginning
	else if (k == 0) {
		newNode->next = leftEnd;
		leftEnd->prev = newNode;
		leftEnd = newNode;
	}

	// in case at the end
	else if (k == length) {
		rightEnd->next = newNode;
		newNode->prev = rightEnd;
		rightEnd = newNode;
	}

	// otherwise, in case in between
	else {
		// iterate untill the position given
		DoubleNode<T> *it = leftEnd;
		for (int i = 0; i < k - 1; i++)
			it = it->next;

		DoubleNode<T> *temp = it->next;
		it->next = newNode;
		newNode->prev = it;
		newNode->next = temp;
		temp->prev = newNode;
	}

	length++;
	return *this;
}

// A method that prints the list to the given stream
template<class T>
void DoublyLinkedList<T>::Output(std::ostream & out) const
{
	// iterate and print every element
	DoubleNode<T> *it = leftEnd;
	while (it != nullptr) {
		out << it->data;
		if (it->next != nullptr)
			out << ", ";
		it = it->next;
	}
}

// A method to check if a list is sorted
template<class T>
bool DoublyLinkedList<T>::Sorted()
{
	if (isEmpty())
		return true;

	DoubleNode<T> *it = leftEnd;
	while (it->next != nullptr) {
		if (it->data > it->next->data)
			return false;
		it = it->next;
	}
	return true;
}
// A method to check if a list is empty
template<class T>
bool DoublyLinkedList<T>::isEmpty() {
	return (length == 0);
}

// A method that checks valid index
template<class T>
void DoublyLinkedList<T>::checkIndex(int index) {
	if (index < 0 || index > length)
		throw std::out_of_range("Index Out of Bounds");
}
