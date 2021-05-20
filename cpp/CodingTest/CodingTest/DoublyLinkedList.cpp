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
	DoublyLinkedListNode<T>* head;
	DoublyLinkedListNode<T>* tail;
public:
	unsigned int length;
	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
		length = 0;
	}
	~DoublyLinkedList() {
		while (head) {
			pop_front();
		}
	}
	void push_front(T val) {
		DoublyLinkedListNode<T>* newHead = new DoublyLinkedListNode<T>(val);
		if (head == nullptr) tail = newHead;
		else {
			head->prev = newHead;
			newHead->next = head;
		}
		head = newHead;
		length++;
	}

	void push_back(T val) {
		DoublyLinkedListNode<T>* newTail = new DoublyLinkedListNode<T>(val);
		if (tail == nullptr) head = newTail;
		else {
			tail->next = newTail;
			newTail->prev = tail;
		}
		tail = newTail;
		this->length++;
	}
	void pop_front() {
		if (head == nullptr) return;
		if (head->next == nullptr) tail = nullptr;
		else {
			head->next->prev = nullptr;
			head = head->next;
		}
		if (length > 0) length--;
	}
	void pop_back() {
		if (tail == nullptr)  return;
		if (this->tail->prev == nullptr) this->head = nullptr;
		else {
			tail->prev->next = nullptr;
			tail = tail->prev;
		}
		if (length > 0) length--;
	}
	void remove(DoublyLinkedListNode<T>* node) {
		if (node.prev == nullptr && node.next == nullptr) {
			head = nullptr;
			tail = nullptr;
			length = 0;
			return;
		}
		if (node->prev == nullptr) {
			head = node->next;
			tail = node->prev;
		}
		else {
			node->prev->next->next = node->prev->next;
			node->prev->next->prev = node->prev;
		}
		if (length > 0) length--;
	}
};

int main() {
	//DoublyLinkedListNode<int>* a = new DoublyLinkedListNode<int>(1);
	//DoublyLinkedListNode<int>* b = new DoublyLinkedListNode<int>(10);
	//a->prev = b;
	//cout << a->prev->value << endl;
	DoublyLinkedList<int>* dll = new DoublyLinkedList<int>();
	dll->push_back(1);
	dll->push_back(2);
	dll->push_back(3);
	dll->pop_front();
	cout << dll->length << endl;

	return 0;
}