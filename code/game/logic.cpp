int checkKey(char userKey, int Ukey){   //cheak keyboard
    switch (userKey){
        case 'd':
            Ukey = 1;
            break;
        case 'a':
            Ukey = 2;
            break;
        case 'w':
            Ukey = 3;
            break;
        case 's':
            Ukey = 4;
            break;
        }
    return Ukey;
}

int moveX(int Ukey,int snakeHeadX){     //move snake head in X
    if (Ukey == 1){
        snakeHeadX++;
    }
    else if (Ukey == 2){
        snakeHeadX--;
    }
    if (snakeHeadX == COLUMNS){
        snakeHeadX = 2;
    }
    else if (snakeHeadX < 2){
        snakeHeadX = COLUMNS - 1;
    }
    return snakeHeadX;
}

int moveY(int Ukey, int snakeHeadY){    //move snake head in Y
    if (Ukey == 3){
        snakeHeady--;
    }
    else if (Ukey == 4){
        snakeHeady++;
    }
    if (snakeHeady == RAWS){
        snakeHeady = 1;
    }
    else if (snakeHeady < 0){
        snakeHeady = RAWS - 1;
    }
    return snakeHeady;
}

int checkApplex(int applex, int appley, int snakex, int snakey){   //new apple X
    srand(time(nullptr));
        applex = rand() % (COLUMNS - 2) + 2;
    
    return applex;
}
int checkAppley(int applex, int appley, int snakex, int snakey){   //new apple Y
    srand(time(nullptr));
   
        appley = rand() % RAWS;
    
    return appley;
}
int ScoreCheck(int score){    // plus one to score
        score++;
    
    return score;
}