#include <iostream>
using namespace std;
template<typename T>
class List
{
public:
	List();
	List(T data);
	~List();

	T& front() { return head->data; };
	void print();
	void push(T data);
	void pop();
	bool empty() const;
	void clear();
	int size() const { return SIZE; };
	

	List(const List<T>& copy);
	List<T>& operator=(const List<T> copy);
	T& operator[](const int index);
	List<T>& operator=(List<T>&&other);
	List(List&& other);

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node * pNext = nullptr)
			: data(data), pNext(pNext)
		{ }
	};

	Node<T>* head;
	Node<T>* curr;
	int SIZE;
};

template<typename T>
inline List<T>::List() {
	SIZE = 0;
	head = nullptr;
	curr = nullptr;
}

template<typename T>
inline List<T>::List(T data) {
	head = nullptr;
	curr = nullptr;
	SIZE = 0;
	
}

template<typename T>
inline List<T>::List( List&& other) {
	clear();
	if (other.head == nullptr) {
		return;
	}

	Node<T>* temp = other.curr->pNext;

	for (int i = 0; i < other.size(); i++) {
		push(temp->data);
		temp = temp->pNext;
	}

	SIZE = other.size();
	other.clear();
}

template<typename T>
inline List<T>::~List() {
	clear();
}

template<typename T>
inline void List<T>::print()
{
	if (empty()) {
		Node<T>* p = curr;
		while (p != head->pNext) {
			cout << p->data << endl;
			p = p->pNext;
			cout << head->data;
		}
	}
	else {
		cout << "pusto";
	}
}

template<typename T>
inline void List<T>::push(T data) {
	Node<T>* temp = new Node<T>(data,head);

	if (!empty()) {
		head = temp;
		curr = temp;
		temp->pNext = head;
		curr = temp;
		
	}
	else{
		curr->pNext = temp;
		curr = curr->pNext;
		curr->pNext = head;
		
	}
	++SIZE;
}

template<typename T>
inline void List<T>::pop() {
	if (!empty()) {
		return;
	}
	Node<T>* temp = curr;

	while (curr->pNext != temp) {
		curr = curr->pNext;
	}
	if (temp == head) {
		head = head->pNext;
	}
	
	delete temp;
	curr->pNext = head;
	--SIZE;
}

template<typename T>
inline bool List<T>::empty() const {
	return curr;
}

template<typename T>
inline void List<T>::clear() {
	for (int i = 0; i < SIZE;) {
		pop();
	}
	head = nullptr;
	curr = nullptr;
}

template<typename T>
inline List<T>::List(const List<T>& copy) {
	clear();
	if (copy.head == nullptr) {
		return;
	}
		
	Node<T>* temp = copy.curr->pNext;

	for (int i = 0; i < copy.size(); i++) {
		push(temp->data);
		temp = temp->pNext;
	}
	
	SIZE = copy.size();
}

template<typename T>
inline List<T>& List<T>::operator=(const List<T> copy) {
	if (this == &copy) {
		return *this;
	}
	clear();
	if (copy.curr == copy.head) {
		return *this;
	}

	Node<T>* temp = copy.curr->pNext;

	for (int i = 0; i < copy.size(); i++) {
		push(temp->data);
		temp = temp->pNext;
	}

	SIZE = copy.size();;
	return *this;
}

template<typename T>
inline T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = curr->pNext;
	if (counter == 0 && index==0){
		return current->data;
	}
	else {
		current = current->pNext;
		counter++;
	}
	while (current!= head) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
inline List<T>& List<T>::operator=(List<T>&& other)
{
	clear();
	if (other.head == nullptr) {
		return *this;
	}
		
	Node<T>* temp = other.curr->pNext;

	for (int i = 0; i < other.size(); i++) {
		push(temp->data);
		temp = temp->pNext;
	}
	
	SIZE = other.size();
	other.clear();
	return *this;
}

