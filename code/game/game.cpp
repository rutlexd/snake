#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <sys/select.h>
#include "map.cpp"
#include "logic.cpp"
using namespace std;

int score = 0;
int applex = COLUMNS / 2 + 4;
int appley = RAWS / 2;
int Ukey = 0;
int snakeHeadx = 5;
int snakeHeady = RAWS / 2;      // defolt values
void game(){


struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // Зберегти старі налаштування

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);  // Вимкнути канонічний та ехо режими
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); 

    fd_set rfds;
    struct timeval tv;
    int retval;

char userKey;


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

                Ukey = checkKey(userKey, Ukey);

                if (userKey == 'q') {
                    cout << "Гра завершена " <<endl;
                    break; // Виход з циклу при натисненні клавіші 'q'
                }
            }
        }

    drawMap(snakeHeadx,snakeHeady, applex, appley, score);
    snakeHeadx = moveX(Ukey, snakeHeadx);
    snakeHeady = moveY(Ukey, snakeHeady);
    if (applex == snakeHeadx && appley == snakeHeady){      //check if snake eat apple
        applex = checkApplex(applex, appley, snakeHeadx, snakeHeady);
        appley = checkAppley(applex, appley, snakeHeadx, snakeHeady);
        score  = ScoreCheck(score);
    }
    usleep(230000);
}
tcsetattr(STDIN_FILENO, TCSANOW, &oldt);


}

