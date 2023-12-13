#ifndef BINARYTREE_ERROR
#define BINARYTREE_ERROR
#include <iostream>
#include <string>
#include "Binar.h"
#include "Menu.h"
#define DEBUG

using namespace std;
class BinaryTreeError
{
public:
	BinaryTreeError() {};
	virtual void ErrMsg() const { std::cerr << "Error with BinaryTree object"; }
	void Continue() const {
#ifdef DEBUG
		cerr << "Debug: program is being continued";
#else
		throw;
#endif	
	}

};

class BinaryTreeFindError: public BinaryTreeError
{
public:
	template<typename T>
	BinaryTreeFindError(T data){

	}
	void ErrMsg()const override{
		cerr << "Ooops... Error of find data " << endl;
		cerr << "Error of data" << endl;
		Continue();
	}

private:
	string err;
};

#endif
