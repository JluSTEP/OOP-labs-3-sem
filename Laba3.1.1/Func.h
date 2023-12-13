#pragma once
#include "List.h"

template<typename T>
void addEl(List<T>& lst) {
	T data;

	system("cls");
	cout << "<3<3<3<3<3 ADDING <3<3<3<3<3" << endl << endl;
	cout << "-~<3 Enter yout data: ";
	cin >> data;

	lst.push(data);
	system("pause");
}

template<typename T>
void removeEl(List<T>& lst) {
	system("cls");
	cout << "<3<3<3<3<3 REVOMING <3<3<3<3<3" << endl << endl;

	lst.pop();
	system("pause");
}

template<typename T>
void showUnderIndex(List<T>& lst) {
	int index;

	system("cls");
	cout << "<3<3<3<3<3 DISPLAY UNDER INDEX <3<3<3<3<3" << endl << endl;
	cout << "-~<3 Enter index: ";
	cin >> index;

	cout << endl << endl << "-~<3 Your element: " << lst[index];
	cout << endl;
	system("pause");
}

template<typename T>
void showList(List<T>& lst) {
	system("cls");
	cout << "<3<3<3<3<3 YOUR LIST <3<3<3<3<3" << endl << endl;
	cout << "-~<3    ";
	for (int i = 0; i < lst.size(); i++) {
		cout << lst[i] << "  ";
	}
	cout << endl;
	system("pause");
}

template<typename T>
void checkEmpty(List<T>& lst) {
	system("cls");
	cout << "<3<3<3<3<3 EMPTY <3<3<3<3<3" << endl << endl;
	cout << "| 0 = empty	|	1 = not empty |"  << endl << endl;
	cout << "-~<3 Yout list: "<<lst.empty();
	cout << endl;
	system("pause");
}

template<typename T>
void copyToNewList(List<T>& lst) {
	List<T> lstSecond(lst);
	system("cls");
	cout << "<3<3<3<3<3 COPY TO NEW LIST <3<3<3<3<3" << endl << endl;

	cout << "-~<3 Your first list: ";
	for (int i = 0; i < lst.size();  i++) {
		cout << lst[i] << "  ";
	}
	cout << endl << endl;

	cout << "-~<3 Your new list: ";
	for (int i = 0; i < lstSecond.size(); i++) {
		cout << lstSecond[i] << "  ";
	}
	cout << endl;

	system("pause");
}

template<typename T>
void clearing(List<T>& lst) {
	system("cls");
	cout << "<3<3<3<3<3 CLEARING <3<3<3<3<3" << endl << endl;
	lst.clear();
	cout << "| 0 = empty	|	1 = not empty |"<< endl << endl;
	cout << "-~<3 Yout list: " << lst.empty();
	cout << endl;
	system("pause");
}