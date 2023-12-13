#include "Menu.h"
#include "Func.h"
#include <iostream>
#include <string>

using namespace std;

void MenuMain() {
    int choice = -1;

    while (choice != 0)
    {
        system("cls");
        cout << " MENU " << endl;
        cout << "1| int" << endl;
        cout << "2| double" << endl;
        cout << "3| string" << endl << endl;
        cout << "0| EXIT" << endl << " YOUR CHOICE... ";

        cin >> choice;
        switch (choice)
        {
        case 1: MenuInt(); break;
        case 2: MenuDouble(); break;
        case 3: MenuString(); break;
        default:
            break;
        }
    }
}

void MenuInt()
{
    List<int> lintFirst;
    int choice = -1;

    while (choice != 0)
    {
        system("cls");
        cout << " MENU INT " << endl;
        cout << "1| add element" << endl;
        cout << "2| remove element" << endl;
        cout << "3| display element under index" << endl;
        cout << "4| display list" << endl;
        cout << "5| check for emptiness" << endl;
        cout << "6| create a new list equal to the given one" << endl;
        cout << "7| clear list" << endl << endl;
        cout << "0| EXIT" << endl << " YOUR CHOICE... ";

        cin >> choice;
        switch (choice)
        {
        case 1: addEl(lintFirst); break;
        case 2: removeEl(lintFirst); break;
        case 3: showUnderIndex(lintFirst); break;
        case 4: showList(lintFirst); break;
        case 5: checkEmpty(lintFirst); break;
        case 6: copyToNewList(lintFirst); break;
        case 7: clearing(lintFirst); break;
        default:
            break;
        }
    }
}
void MenuDouble(){
    List<double> ldblFirst;
    int choice = -1;

    while (choice != 0)
    {
        system("cls");
        cout << " MENU DOUBLE " << endl;
        cout << "1| add element" << endl;
        cout << "2| remove element" << endl;
        cout << "3| display element under index" << endl;
        cout << "4| display list" << endl;
        cout << "5| check for emptiness" << endl;
        cout << "6| create a new list equal to the given one" << endl;
        cout << "7| clear list" << endl << endl;
        cout << "0| EXIT" << endl << " YOUR CHOICE... ";

        cin >> choice;
        switch (choice)
        {
        case 1: addEl(ldblFirst); break;
        case 2: removeEl(ldblFirst); break;
        case 3: showUnderIndex(ldblFirst); break;
        case 4: showList(ldblFirst); break;
        case 5: checkEmpty(ldblFirst); break;
        case 6: copyToNewList(ldblFirst); break;
        case 7: clearing(ldblFirst); break;
        default:
            break;
        }
    }

}
void MenuString() {
    List<string> lstrFirst;
    int choice = -1;

    while (choice != 0)
    {
        system("cls");
        cout << " MENU STRING " << endl;
        cout << "1| add element" << endl;
        cout << "2| remove element" << endl;
        cout << "3| display element under index" << endl;
        cout << "4| display list" << endl;
        cout << "5| check for emptiness" << endl;
        cout << "6| create a new list equal to the given one" << endl;
        cout << "7| clear list" << endl << endl;
        cout << "0| EXIT" << endl << " YOUR CHOICE... ";

        cin >> choice;
        switch (choice)
        {
        case 1: addEl(lstrFirst); break;
        case 2: removeEl(lstrFirst); break;
        case 3: showUnderIndex(lstrFirst); break;
        case 4: showList(lstrFirst); break;
        case 5: checkEmpty(lstrFirst); break;
        case 6: copyToNewList(lstrFirst); break;
        case 7: clearing(lstrFirst); break;
        default:
            break;
        }
    }
}