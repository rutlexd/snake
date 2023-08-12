#include <iostream>
#include <ncurses.h>
#include "menu/switchmenu.cpp"
#include "game/game.cpp"
using namespace std;

int checkMenu(int key);

int main(){
cout << "\e[8;27;90t";
showMenu();
checkMenu(key);
}

int checkMenu(int key){
    if(key == 1){
        game();
    }
    else if(key == 2){

    }
    else if(key == 3){

    }
    else if(key == 4){
        return 0;
    }
    return 0;
}
