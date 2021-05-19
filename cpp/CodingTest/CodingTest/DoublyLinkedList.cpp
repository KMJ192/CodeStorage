#include<iostream>

using namespace std;

template<class T>
struct DoublyLinkedListNode {
	T value;
    DoublyLinkedListNode<T>* prev;
	DoublyLinkedListNode<T>* next;
	DoublyLinkedListNode(T val) : value(val), prev(nullptr), next(nullptr) {}
};

template<class T>
class DoublyLinkedList {
private:
	DoublyLinkedList<T>* head;
	DoublyLinkedList<T>* tail;
	unsigned int length;
public:
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
	~DoublyLinkedList() {}
	void push_front(T val) {

	}
	void push_back(T val) {

	}
	void pop_front() {

	}
	void pop_back() {

	}
};

int main() {
	DoublyLinkedListNode<int>* a = new DoublyLinkedListNode<int>(1);
	DoublyLinkedListNode<int>* b = new DoublyLinkedListNode<int>(10);
	a->prev = b;
	cout << a->prev->value << endl;


	return 0;
}