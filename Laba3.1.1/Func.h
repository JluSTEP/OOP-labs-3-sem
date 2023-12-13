#pragma once
#include "List.h"

template<typename T>
void addEl(List<T>& lst) {
	T data;

	system("cls");
	cout << " ADDING " << endl << endl;
	cout << " Enter yout data: ";
	cin >> data;

	lst.push(data);
	system("pause");
}

template<typename T>
void removeEl(List<T>& lst) {
	system("cls");
	cout << " REVOMING " << endl << endl;

	lst.pop();
	system("pause");
}

template<typename T>
void showUnderIndex(List<T>& lst) {
	int index;

	system("cls");
	cout << " DISPLAY UNDER INDEX" << endl << endl;
	cout << " Enter index: ";
	cin >> index;

	cout << endl << endl << " Your element: " << lst[index];
	cout << endl;
	system("pause");
}

template<typename T>
void showList(List<T>& lst) {
	system("cls");
	cout << "YOUR LIST" << endl << endl;
	cout << "    ";
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << "  ";
	}
	cout << endl;
	system("pause");
}

template<typename T>
void checkEmpty(List<T>& lst) {
	system("cls");
	cout << " EMPTY " << endl << endl;
	cout << "| 0 = empty	|	1 = not empty |"  << endl << endl;
	cout << "Yout list: "<<lst.empty();
	cout << endl;
	system("pause");
}

template<typename T>
void copyToNewList(List<T>& lst) {
	List<T> lstSecond(lst);
	system("cls");
	cout << " COPY TO NEW LIST " << endl << endl;

	cout << " Your first list: ";
	for (int i = 0; i < lst.size();  i++) {
		cout << lst[i] << "  ";
	}
	cout << endl << endl;

	cout << "Your new list: ";
	for (int i = 0; i < lstSecond.size(); i++) {
		cout << lstSecond[i] << "  ";
	}
	cout << endl;

	system("pause");
}

template<typename T>
void clearing(List<T>& lst) {
	system("cls");
	cout << " CLEARING" << endl << endl;
	lst.clear();
	cout << "| 0 = empty	|	1 = not empty |"<< endl << endl;
	cout << " Yout list: " << lst.empty();
	cout << endl;
	system("pause");
}
