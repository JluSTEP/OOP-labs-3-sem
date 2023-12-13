#pragma once
#include <iostream>
using namespace std;

template<typename T>
class APtr
{
public:
	APtr();
	APtr(int size);
	~APtr();
	
	T& operator*() const;
	T* operator->()const;

	T& operator[](int data);	//замена get() и оператора*
	T* get() const throw() { return ptr; }
	int getSize() { return size; }

	APtr<T>& operator=(APtr<T>& copy);	//оператор перемещения
	APtr( APtr<T>& copy);	//конструктор перемещения
	
protected:
	int size;
private:
	T* ptr;
};

template<typename T>
inline APtr<T>::APtr() {
	size = 1;
	ptr = new T[1];
}

template<typename T>
inline APtr<T>::APtr(int size) {
	if (size > 0) {
		this->size = size;
		ptr = new T[size];
	}
	else {
		throw "ERROR: ARRAY CANT BE NEGATIVE";
	}
}

template<typename T>
inline APtr<T>::~APtr() {
	delete[] ptr;
}

template<typename T>
inline T& APtr<T>::operator*() const {
	return *ptr;
}

template<typename T>
inline T* APtr<T>::operator->() const {
	return ptr;
}

template<typename T>
inline APtr<T>& APtr<T>::operator=(APtr<T>& copy) {
	if (copy.get() == nullptr) {
		return *this; 
	}
	size = copy.size;

	ptr = new T[copy.size];
	for (int i = 0; i < copy.size; i++) {
		ptr[i] = copy[i];
	}

	copy.ptr = nullptr;
	return *this;
}

template<typename T>
inline APtr<T>::APtr(APtr<T>& copy) {
	size = copy.size;
	ptr = new T[copy.size];

	for (int i = 0; i < copy.size; i++) {
		ptr[i] = copy.get()[i];
	}
	
	copy.ptr = nullptr;
}

template<typename T>
inline T& APtr<T>::operator[](int data) {
	if (ptr == nullptr) {
		return *ptr;
	}
	if (data>=0 && data<=size) {
		return ptr[data];
	}
	else {
		throw("ERROR OF RANGE");
	}
}

