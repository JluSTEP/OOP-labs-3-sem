#include <iostream>
#include "Binar.h"
#include "Menu.h"
#include "Func.h"
#include "ExeptionBT.h"

using namespace std;


void mainMenu()
{
    int choice = -1;

    while (choice != 0)
    {
        system("cls");
        cout << " MENU MAIN " << endl;
        cout << "1| INT" << endl;
        cout << "2| STRING" << endl;
        cout << "3| DOUBLE" << endl;
        cout << "0| Exit" << endl << "Please, choose something";

        cin >> choice;
        switch (choice)
        {
        case 1: MenuInt(); break;
        case 2: MenuString(); break;
        case 3: MenuDouble(); break;
        default:
            break;
        }
    }
}

template<typename T>
void MenuT(BinaryTree <T> dt)
{
    int choice = -1;
    while (choice != 0)
    {
        system("cls");
        cout << " MENU " << endl;
        cout << "1| Insert element" << endl;
        cout << "2| Erase element" << endl;
        cout << "3| Display tree" << endl;
        cout << "4| Check for emptiness" << endl;
        cout << "5| Find element" << endl;
        cout << "6| Copy BinaryTree" << endl;
        cout << "0| Exit" << endl << "Please, choose something";

        cin >> choice;
        switch (choice)
        {
        case 1: addEl(dt); break;
        case 2: removeEl(dt); break;
        case 3: showBinaryTree(dt); break;
        case 4: checkEmpty(dt); break;
        case 5: find(dt); break;
        case 6: copyToNewList(dt); break;
        default:
            break;
        }
    }
}

void MenuInt() {
    BinaryTree<int> dt;
    MenuT(dt);
}
void MenuString() {
    BinaryTree<string> dt;
    MenuT(dt);
}
void MenuDouble() {
    BinaryTree<double> dt;
    MenuT(dt);
}

