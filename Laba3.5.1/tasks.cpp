#include "tasks.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

using namespace std;

void exOne() {
    system("cls");
    cout << " EXERCISE ¹1 " << endl << endl;

    cout << fixed;
    for (double t = 0; t < 3; t += 0.5)
    {
        cout.width(10);
        cout.precision(3);
        cout << cos(t) << endl;
    }
    cout << endl;

    system("pause");
}

void exTwo() {
    system("cls");
    cout << " EXERCISE ¹2 " << endl << endl;

    ofstream fout("first.txt");
    cout << "file \"first.txt\" created" << endl;

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(-50, 50);

    int odd = -11;

    for (int i = 0; i < 100; ++i) {
        int rnd = dist(mt);

        if (odd == -11 && rnd % 2 != 0)
            odd = abs(rnd);

        fout << rnd << '\n';
    }

    fout.close();

    ifstream fin("first.txt");
    ofstream sout("second.txt");
    cout << "file \"second.txt\" created" << endl;
    while (fin.peek() != EOF) {
        int tmp;
        fin >> tmp;

        sout << tmp + odd << '\n';
    }

    fin.close();
    sout.close();


    system("pause");
}

void Menu() {
    int choice = -1;

    while (choice!= 0)
    {
        system("cls");
        cout << " MENU " << endl;
        cout << "1| exercise one" << endl;
        cout << "2| exercise two" << endl<<endl;
        cout << "0| EXIT" << endl << " YOUR CHOICE... ";

        cin >> choice;
        switch (choice)
        {
        case 1: exOne(); break;
        case 2: exTwo(); break;
        default:
            break;
        }
    }
      
}

