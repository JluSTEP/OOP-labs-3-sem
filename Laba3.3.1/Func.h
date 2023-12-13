#include "Task.h"

template<typename T>
void creatArr(APtr<T>& ptr) {
	int sizeInt;
	system("cls");
	cout << " ADDING " << endl << endl;
	cout << "- Enter size of arr: ";
	cin >> sizeInt;
	APtr<T> ptr2(sizeInt);

	ptr = ptr2;
	system("pause");
}
template<typename T>
void addEl(APtr<T>& ptr) {
	T data;
	system("cls");
	cout << " ADDING " << endl << endl;
	cout << " Enter yout data: ";
	
	for (int i = 0; i < ptr.getSize(); i++){
		cin >> data;
		ptr[i] = data;
		cout << " " << endl;
	}

	system("pause");
}
template<typename T>
void showUnderIndex(APtr<T>& ptr) {
	int index;

	system("cls");
	cout << " DISPLAY UNDER INDEX " << endl << endl;
	cout << " Enter index: ";
	cin >> index;

	cout << endl << endl << " Your element: " << ptr[index];
	cout << endl;
	system("pause");
}

template<typename T>
void showArr(APtr<T>& ptr) {
	system("cls");
	cout << "YOUR ARR " << endl << endl;
	cout << "    ";
	for (int i = 0; i < ptr.getSize(); i++) {
		cout << ptr[i] << "  ";
	}
	cout << endl;
	system("pause");
}

template<typename T>
void removeToNewArr(APtr<T>& ptr) {
	APtr<T> ptr2;
	system("cls");
	cout << " REMOVE TO NEW ARR " << endl << endl;

	cout << " Your first arr: ";
	for (int i = 0; i < ptr.getSize(); i++) {
		cout << ptr[i] << "  ";
	}
	cout << endl << endl;
	ptr2 = ptr;
	cout << " Your new arr: ";
	for (int i = 0; i < ptr2.getSize(); i++) {
		cout << ptr2[i] << "  ";
	}
	cout << endl << endl;
	cout << "Your first arr pointer: " << &ptr[0] << endl;

	system("pause");
}