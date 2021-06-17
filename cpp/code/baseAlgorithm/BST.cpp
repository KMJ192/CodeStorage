#include<iostream>
using namespace std;

template<typename T>
struct Node {
	Node* left;
	Node* rigth;
	T value;
};

template<typename T>
class BST{
public:
	BST() {};
	~BST() {};
	void addNode(T _value);
	void removeNode(T _value);
	void print();
	bool searchNode(T _value);
private:
	Node<T>* root;
	Node<T> tail;

	void Inorder(Node<T>* current) {
		if (current != nullptr) {
			Inorder(current->left);
			cout << current->value << " ";
			Inorder(current->rigth);
		}
	}
	Node<T>* searchMaxNode(Node<T>* node) {
		if (node == nullptr) {
			return nullptr;
		}
		while (node->rigth != nullptr) {
			node = node->rigth;
		}
		return node;
	}
	Node<T>* searchMinNode(Node<T>* node) {
		if (node == nullptr) {
			return nullptr;
		}
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	Node<T>* removeConnect(Node<T>* node, T _value) {
		if (node == nullptr) return node;
		else if (node->value > _value) node->left = removeConnect(node->left, _value);
		else if (node->value < _value) node->rigth = removeConnect(node->rigth, _value);
		else {
			//삭제 알고리즘의 3가지 상황
			//1. no chlid
			//2. one child
			//3. 2 child
			Node<T>* ptr = node;
			if (node->rigth == nullptr && node->left == nullptr) {
				delete node;
				node = nullptr;
			}
			else if (node->rigth == nullptr) {
				node = node->left;
				delete ptr;
			}
			else if (node->left == nullptr) {
				node = node->rigth;
				delete ptr;
			}
			else {
				ptr = searchMaxNode(node->left);
				node->value = ptr->value;
				node->left = removeConnect(node->left, ptr->value);
			}
		}
		return node;
	}
};

template<typename T>
void BST<T>::addNode(T _value){
	if (searchNode(_value)) return;

	Node<T>* node = new Node<T>();
	Node<T>* tmp = nullptr;

	node->value = _value;
	if (root == nullptr) root = node;
	else {
		Node<T>* ptr = root;
		while (ptr != nullptr) {
			tmp = ptr;
			if (node->value < ptr->value) ptr = ptr->left;
			else ptr = ptr->rigth;
		}
		if (node->value < tmp->value) tmp->left = node;
		else tmp->rigth = node;
	}

	
}

template<typename T>
void BST<T>::removeNode(T _value){
	removeConnect(root, _value);
}

template<typename T>
void BST<T>::print(){
	Inorder(root);
}

template<typename T>
bool BST<T>::searchNode(T _value){
	Node<T>* ptr = root;
	Node<T>* tmp = nullptr;

	while (ptr != nullptr) {
		if (ptr->value == _value) return true;
		else if (ptr->value > _value) ptr = ptr->left;
		else ptr = ptr->rigth;
	}

	return false;
}


int main() {

	BST<int>* bst = new BST<int>();
	bst->addNode(1);
	bst->addNode(2);
	bst->addNode(4);
	bst->addNode(3);
	bst->addNode(5);
	bst->addNode(6);
	bst->print();
	bst->removeNode(2);
	bst->print();

	return 0;
}

