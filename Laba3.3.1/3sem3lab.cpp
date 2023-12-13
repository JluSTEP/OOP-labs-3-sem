#include <iostream>
#include "Menu.h"
using namespace std;
int main()
{
    try{
        MenuMain();
    }
    catch(const char* err){
        cout<<err;
    }
    return 0;
}

 