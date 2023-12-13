#include <iostream>
#include "Binar.h"
#include "ExeptionBT.h"

using namespace std;
int main()
{
    try {
        try {
            BinaryTree<int> b1;

            b1.insert(5);
            b1.insert(3);
            b1.insert(7);
            b1.insert(2);
            b1.insert(4);
            b1.insert(6);
            b1.insert(8);
            b1.insert(10);

         

            BTDeepIterator<BinaryTree<int>> iter(b1.beginD());
            while (iter.hasNext()) {
                int data = iter.next();
                cout << data << " " << endl;

            }
            cout << endl;
            BTBreadthIterator<BinaryTree<int>> iter2(b1.beginB());
            while (iter2.hasNext()) {
                int data = iter2.next();
                cout << data << " " << endl;

            }
        }
        catch (BinaryTreeError& ex) { ex.ErrMsg(); }
    }
    catch (...) { cerr << "Epilogue: error of Main" << endl; }
    return 0;
}
