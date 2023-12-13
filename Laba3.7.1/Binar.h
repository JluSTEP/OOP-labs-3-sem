#pragma once
#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
#include <stack>
#include <queue>
#include "ExeptionBT.h"

using namespace std;

template<typename BinaryTree>
class BTDeepIterator
{
public:
	using ValueType = typename BinaryTree::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
	using BTvalue = typename BinaryTree::BTvalue;

public:
	BTDeepIterator(PointerType ptr)
		: myPointer(ptr) {
		stack.push(ptr);
	}
	
	BTvalue next() {
		PointerType current = stack.top();
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
		return current->data;
	}

	bool hasNext() {
		return !stack.empty();
	}
private:
	PointerType myPointer;
	stack<PointerType> stack;
};

template<typename BinaryTree>
class BTBreadthIterator
{
public:
	using ValueType = typename BinaryTree::ValueType;
	using PointerType = ValueType*;
	using ReferenceType = ValueType&;
	using BTvalue = typename BinaryTree::BTvalue;

public:
	BTBreadthIterator(PointerType ptr)
		: myPointer(ptr) {
		que.push(ptr);

	}

	BTvalue next() {
		PointerType current = que.front();
		que.pop();
		if (current->left) {
			que.push(current->left);
		}
		if (current->right) {
			que.push(current->right);
		}
		return current->data;
	}

	bool hasNext() {
		return !que.empty();
	}
private:
	PointerType myPointer;
	queue<PointerType> que;
};
//typedef<typename T>
//class DepthFirstIterator {
//public:
//	DepthFirstIterator(Node<T>* rootNode) {
//		if (rootNode) {
//			stack.push(rootNode);
//		}
//	}
//
//	T next() {
//		Node* current = stack.top();
//		stack.pop();
//
//		if (current->right) {
//			stack.push(current->right);
//		}
//
//		if (current->left) {
//			stack.push(current->left);
//		}
//
//		return current->data;
//	}
//
//	bool hasNext() {
//		return !stack.empty();
//	}
//
//private:
//	std::stack* <T>stack;
//};
template<typename T>
class Node
{
public:
	Node* left;
	Node* right;
	T data;

	Node(T data){
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

template<typename T>
class BinaryTree
{
public:
	using ValueType = Node<T>;
	using IteratorD = BTDeepIterator<BinaryTree<T>>;
	using IteratorB = BTBreadthIterator<BinaryTree<T>>;
	using BTvalue = T;
	BinaryTree();
	BinaryTree(T data);
	~BinaryTree() { clear(head); head == nullptr; };

	void insert(T data);
	void print();
	T find(T data);
	void erase(T data);
	int size() const { return SIZE; };
	bool empty() const { return head; }
	IteratorD beginD() { return IteratorD(head); }
	IteratorD endD() {
		Node<T>* current = head;
		while (current->right != nullptr) {
			current = current->right;
		}
		return IteratorD(current);
	}
	IteratorB beginB() { return IteratorB(head); }
	IteratorB endB() {
		Node<T>* current = head;
		while (current->right != nullptr) {
			current = current->right;
		}
		return IteratorB(current);
	}

	BinaryTree(const BinaryTree<T>& copy);
	//BinaryTree( BinaryTree<T>& other);

	BinaryTree<T>& operator=(const BinaryTree<T>& copy);
	//BinaryTree<T>& operator=( BinaryTree<T>& other);

protected:
	void clear(Node<T>* current);
	Node<T>* head;

private:
    int SIZE;
	void printHelper(Node<T>* current);
	Node<T>* copyHelper(Node<T>* current);
};

template<typename T>
inline BinaryTree<T>::BinaryTree()
{
	head = nullptr;
	SIZE = 0;
}

template<typename T>
inline BinaryTree<T>::BinaryTree(T data){
	head = new Node<T>(data);
	SIZE = 1;
}

template<typename T>
inline void BinaryTree<T>::insert(T data)
{
	Node<T>* current = head;

	if (current == nullptr) {
		head = new Node<T>(data);
		SIZE = 1;
		return;
	}
	while (current && current->data != data) {
		if (current->data > data && current->left == nullptr) {
			current->left = new Node<T>(data);
			++SIZE;
			return;
		}
		if (current->data < data && current->right == nullptr) {
			current->right = new Node<T>(data);
			++SIZE;
			return;
		}
		if (current->data > data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

}

template<typename T>
inline void BinaryTree<T>::clear(Node<T>* current)
{
	if (current) {
		clear(current->left);
		clear(current->right);
		delete current;
		SIZE--;
	}
	
}

template<typename T>
inline void BinaryTree<T>::print()
{
	printHelper(head);
}

template<typename T>
inline T BinaryTree<T>::find(T data)
{
	Node<T>* current = head;
	while (current && current->data != data) {
		if (current->data > data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (current != nullptr) {
		return current->data;
	}
	else {
		throw BinaryTreeFindError(data);
	}
}

template<typename T>
inline void BinaryTree<T>::erase(T data)
{
	Node<T>* current = head;
	Node<T>* parent = nullptr;
	
	while (current && current->data != data) {
		parent = current;
		if (current->data > data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (!current) {
		return;
	}

	if (current->left == nullptr && current->right == nullptr) {
		if (parent && parent->right == current) {
			parent->right = nullptr;
		}
		if (parent && parent->left == current) {
			parent->left = nullptr;
		}
		--SIZE;
		delete current;
		return;
	}

	if (current->left == nullptr) {
		if (parent && parent->left == current) {
			parent->left = current->right;
		}
		if (parent && parent->right == current) {
			parent->right = current->right;
		}
		--SIZE;
		delete current;
		return;
	}
	if (current->right == nullptr) {
		if (parent && parent->right == current) {
			parent->right = current->left;
		}
		if (parent && parent->left == current) {
			parent->left = current->left;
		}
		--SIZE;
		delete current;
		return;
	}
	

	Node<T>* replace = current->right;
	while (replace->left) {
		replace = replace->left;
	}

	T replaceData = replace->data;
	erase(replace->data);
	current->data = replaceData;
}

template<typename T>
inline BinaryTree<T>::BinaryTree(const BinaryTree<T>& copy)
{
	head = copyHelper(copy.head);
	
}

//template<typename T>
//inline BinaryTree<T>::BinaryTree( BinaryTree<T>& other) {
//	head = copyHelper(other.head);
//	other.clear(other.head);
//	other.head = nullptr;
//
//}

template<typename T>
inline BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& copy)
{
	if (this == &copy) {
		return *this;
	}

	clear(head);

	if (copy.head == nullptr) {
		return *this;
	}

	head = copyHelper(copy.head);
	return *this;
}

//template<typename T>
//inline BinaryTree<T>& BinaryTree<T>::operator=( BinaryTree<T>& other){
//	if (this == &other) {
//		return *this;
//	}
//
//	clear(head);
//
//	if (other.head == nullptr) {
//		return *this;
//	}
//
//	head = copyHelper(other.head);
//	other.clear(other.head);
//	other.head = nullptr;
//	return *this;
//}

template<typename T>
inline void BinaryTree<T>::printHelper(Node<T>* current)
{
	if (current) {
		printHelper(current->left);
		cout << current->data << " ";
		printHelper(current->right);
	}
}

template<typename T>
inline Node<T>* BinaryTree<T>::copyHelper(Node<T>* copy)
{
	if (copy == nullptr) {
		return nullptr;
	}
	
	Node<T>* current = new Node<T>(copy->data);
	current->left = copyHelper(copy->left);
	current->right = copyHelper(copy->right);

	++SIZE;

	return current;
}

#endif



