#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
using namespace std;
int checkBorder(int snakeX,const int COLUMNS);
int checkBorder(int snakeY);
void playerMove(){
    bool moveRight = true;
    bool moveLeft = false;
    bool moveUp = false;
    bool moveDown = false;
    bool apple = true;
    int snakex = 0;
    int snakey = 22;
    char snakeHead = 'O';

 struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // Зберегти старі налаштування

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Вимкнути канонічний та ехо режими
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 

    fd_set rfds;
    struct timeval tv;
    int retval;

char userKey;
const int RAWS = 23;
const int COLUMNS = 34;
const int BORDERS = 36;
int befSH;
int aftSH;
int mid;
int befA;
int aftA;

srand(static_cast<int>(time(nullptr)));

    int applex = rand() % 34;
    int appley = rand() % 23;
    int score = 0;
while(true){
    FD_ZERO(&rfds);
        FD_SET(STDIN_FILENO, &rfds);

        tv.tv_sec = 0;
        tv.tv_usec = 0;

        retval = select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv);

        if (retval == -1) {
            perror("select()");
        } else if (retval > 0) {
            if (read(STDIN_FILENO, &userKey, 1) > 0) {
                
                switch (userKey)                //Перевірка клавіатури
                {
                case 'd':
                        moveLeft = false;
                        moveRight = true;
                        moveUp = false;
                        moveDown = false;
                    break;
                case 'a':
                        moveLeft = true;
                        moveRight = false;
                        moveUp = false;
                        moveDown = false;
                    break;
                case 'w':
                        moveLeft = false;
                        moveRight = false;
                        moveUp = true;
                        moveDown = false;
                    break;
                case 's':
                        moveLeft = false;
                        moveRight = false;
                        moveUp = false;
                        moveDown = true;
                    break;
                }

                cout << "Гра завершена " << userKey << endl;

                if (userKey == 'q') {
                    break; // Виход з циклу при натисненні клавіші 'q'
                }
            }
        }
           
   
    char apple = 'A';

    
    
    int temp = 0;
    for(int i = 0;i<BORDERS;i++){
        cout<<"*";
    }
    cout<<" sn "<<snakey<<" "<<snakex<<" ap "<<appley<<" "<<applex<<" score - "<<score;
    cout<<endl;
    if(snakex == applex && snakey == appley){
        applex = rand() % COLUMNS;
        appley = rand() % RAWS;
        score++;
    }
    for(int raw = 0;raw<RAWS;raw++){
        
    cout<<"*";


    for(befSH = 0;befSH<snakex&& raw != appley;befSH++){
        cout<<"-";
    }
    for(befA = 0;befA<applex && raw == appley && raw != snakey;befA++){
        cout<<"-";
    }
    for(befSH = 0;befSH<snakex&& raw == appley && raw == snakey && snakex < applex;befSH++){
        cout<<"-";
    }
    for(befA = 0;befA<applex&& raw == appley && raw == snakey && applex < snakex;befA++){
        cout<<"-";
    }
    if(moveRight && raw == snakey){     //Якщо рядок відповідає голові змійці та ми ідемо  право
                
        cout<<snakeHead;
        snakex++;
        
        
    }
    else if(moveLeft && raw == snakey){     //Якщо рядок відповідає голові змійці та ми ідемо  вліво

        cout<<snakeHead;
        snakex--;
    }

    else if(moveDown && raw == snakey&& temp == 0){
        temp++;
        snakey++;
        cout<<snakeHead;
    }
    
    else if(moveUp && raw == snakey){       //Якщо рядок відповідає голові змійці та ми ідемо  вверх
        snakey--;
        cout<<snakeHead;
    }

   
    if(raw == appley && raw == snakey || raw == appley && raw == snakey - 1){
    if(snakex < applex){
    for(mid = snakex + 1; mid < applex ;mid++){
        cout<<"+";
    }
    
    }
    else if(snakex > applex){
    for(mid = applex; mid < snakex;mid++){
        cout<<"+";
    }
    }
    }
         if(raw == appley){
        cout<<apple;
        }

 
    for(aftSH = snakex+1;aftSH < COLUMNS&& raw != appley;aftSH++){
        cout<<"-";
    }
      

    


    cout<<"*";
     cout<<" sn "<<snakey<<" "<<snakex<<" ap "<<appley<<" "<<applex<<" score - "<<score;
    cout<<endl;
    snakex = checkBorder(snakex,COLUMNS);                           //Перевіряємо координати, якщо виходять за границі змінюємо
    snakey = checkBorder(snakey);
}

for(int i = 0;i<BORDERS;i++){
        cout<<"*";
    }
    cout<<endl;
usleep(230000);
}
tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int checkBorder(int snakeX,const int COLUMNS){
    int res;
    if(snakeX > COLUMNS - 1){
        res = 0;
    }
    else if(snakeX < 0){
        res = COLUMNS -1;
    }
    else{
        res = snakeX;
    }
    return res;
}

int checkBorder(int snakeY){
    int res;
    const int RAWS = 23;
    if(snakeY > RAWS - 1 ){
        res = 0;
    }
    else if(snakeY < 0){
        res = RAWS -1 ;
    }
    else{
        res = snakeY;
    }
    return res;
}