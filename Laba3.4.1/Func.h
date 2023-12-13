#pragma once
#include "Binar.h"

template<typename T>
void addEl(BinaryTree<T>& lst)
{
	T data;

	system("cls");
	cout << "ADDING" << endl << endl;
	cout << " Enter your data: ";
	cin >> data;

	lst.insert(data);
	system("pause");
}

template<typename T>
void removeEl(BinaryTree<T>& lst)
{
	T data;
	system("cls");
	cout << "REVOMING" << endl << endl;
	cout << " Enter your data to remove: ";
	cin >> data;

	lst.erase(data);

	system("pause");
}


template<typename T>
void showBinaryTree(BinaryTree<T>& lst)
{
	system("cls");
	cout << "YOUR BINARYTREE" << endl << endl;
	cout << "    ";
	lst.print();
	cout << endl;
	system("pause");
}

template<typename T>
void checkEmpty(BinaryTree<T>& lst)
{
	system("cls");
	cout << " EMPTY " << endl << endl;
	cout << "| 0 = empty	|	1 = not empty |" << endl << endl;
	cout << " Yout BinaryTree: " << lst.empty();
	cout << endl;
	system("pause");
}

template<typename T>
void copyToNewList(BinaryTree<T>& lst)
{
	BinaryTree<T> lstSecond(lst);
	system("cls");
	cout << "COPY TO NEW LIST" << endl << endl;

	cout << " Your first list: ";
	lst.print();
	cout << endl << endl;

	cout << " Your new list: ";
	lstSecond.print();
	cout << endl;

	system("pause");
}

template<typename T>
void find(BinaryTree<T>& lst)
{
	T data;
	system("cls");
	cout << "FIND ELEMENT" << endl << endl;
	cout << " Enter your data to find: ";
	cin >> data;
	cout << endl;
	lst.find(data);

	cout <<"Data was found" << endl;
	system("pause");
}