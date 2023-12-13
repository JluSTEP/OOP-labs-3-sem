#include "Menu.h"
#include "Func.h"
#include <iostream>
#include <string>

using namespace std;

template<typename T>
void MenuT (APtr<T> ptr) {
    int choice = -1;
    while (choice != 0) {
        system("cls");
        cout << " MENU " << endl;
        cout << "1| creatArr" << endl;
        cout << "2| addEl" << endl;
        cout << "3| showUnderIndex" << endl;
        cout << "4| showArr" << endl;
        cout << "5| removeToNewArr" << endl;
        cout << "0| EXIT" << endl << " YOUR CHOICE... ";

        cin >> choice;
        switch (choice)
        {
        case 1: creatArr(ptr); break;
        case 2: addEl(ptr); break;
        case 3: showUnderIndex(ptr); break;
        case 4: showArr(ptr); break;
        case 5: removeToNewArr(ptr); break;
        default:
            break;
        }
    }
}

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
void MenuInt(){
    APtr <int> ArrInt;
    MenuT(ArrInt);
}
void MenuDouble() {
    APtr <double> ArrDoub;
    MenuT(ArrDoub);
};
void MenuString() {
    APtr <string> ArrStr;
    MenuT(ArrStr);
};
