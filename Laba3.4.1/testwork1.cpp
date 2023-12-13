#include <iostream>
#include "Binar.h"
#include "ExeptionBT.h"
#include "Menu.h"

using namespace std;
int main()
{
    try {
        try {
            mainMenu();
        }
        catch (BinaryTreeError& ex) { ex.ErrMsg(); }
    }
    catch (...) { cerr << "Epilogue: error of Main" << endl; }
    return 0;
}
