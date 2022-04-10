#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"
using namespace std;
int main() {
	DoublyLinkedList<int> list;
	cout << "DoublyLinkedList :"cout<<endl;

	list.Insert(0, 3);
	list.Insert(1, 2);
	list.Insert(2, 8);
	list.Insert(3, 11);
	list.Insert(4, 9);
	list.Insert(5, 1);
	// sorted method to cheak if the elements is sorted
	cout << "isSorted: " << list.Sorted();
	system("pause");
	return 0;
}
