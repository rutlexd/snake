#include <fstream>
#include <termios.h>
#include <unistd.h>
#include <iostream>
using namespace std;

char geter();

void show(int key){
    ifstream start("/home/max/snake/resurs/menuBar/menuS.txt");
    ifstream score("/home/max/snake/resurs/menuBar/menuH.txt");
    ifstream options("/home/max/snake/resurs/menuBar/menuO.txt");
    ifstream exit("/home/max/snake/resurs/menuBar/menuE.txt");
    if(key == 1){
            if(start.is_open()){
        cout<<start.rdbuf();
    }
    }
    else if(key == 2){
        if(score.is_open()){
        cout<<score.rdbuf();
    }
    }
    else if(key == 3){
        if(options.is_open()){
        cout<<options.rdbuf();
    }
    }
    else if(key == 4){
        if(exit.is_open()){
        cout<<exit.rdbuf();
    }
    }
    
}
int key = 1;
void showMenu(){
    int keyPressed;
    show(1);
    do{
    keyPressed = geter();
    if (keyPressed == 's'){
        key++;
        if(key > 4){
            key = 1;
        }
        show(key);
        
    }
    else if(keyPressed == 'w'){
        key--;
        if(key == 0){
            key = 4;
        }
        show(key);
    }
    }while(keyPressed != 10);
}

char geter() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return buf;
}