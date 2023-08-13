#include <iostream>

void drawBorder();
void drawBorder(int score, int sx, int sy, int ax, int ay);

const int RAWS = 10;
const int COLUMNS = 15;
char SnakeHead = 'O';
char Apple = 'A';
void drawMap(int snakex, int snakey, int applex, int appley, int score){

int  befSH, aftSH, befA, aftA, midSA, midAS, fill, raw;

drawBorder(score, snakex, snakey, applex, appley);
for (raw = 0; raw < RAWS; raw++){
    cout<<"*";
    if (raw == snakey && raw != appley){    //draw raw with snake head
        for (befSH = 2; befSH < snakex; befSH++){
            cout<<"-";
        }
        cout<<SnakeHead;
        for (aftSH = snakex + 1; aftSH < COLUMNS; aftSH++){
            cout<<"-";
        }
    }
    else if (raw == appley && raw != snakey){ //draw raw with apple
        for (befA = 2; befA < applex; befA++){
            cout<<"-";
        }
        cout<<Apple;
        for (aftA = applex + 1; aftA < COLUMNS; aftA++){
            cout<<"-";
        }
    }
    else if (raw == snakey && raw == appley){   //draw raw with snake head and apple
        if(snakex < applex){
            for (befSH = 2; befSH < snakex; befSH++){
            cout<<"-";
            }
            cout<<SnakeHead;
            for(midSA = snakex + 1; midSA <applex; midSA++){
                cout<<"-";
            }
            cout<<Apple;
            for (aftA = applex + 1; aftA<COLUMNS; aftA++){
            cout<<"-";
        }
        }
        else if (snakex > applex){
            for (befA = 2; befA<applex; befA++){
                cout<<"-";
            }
            cout<<Apple;
            for(midAS = applex + 1; midAS < snakex; midAS++){
                cout<<"-";
            }
            cout<<SnakeHead;
            for (aftSH = snakex + 1; aftSH<COLUMNS; aftSH++){
            cout<<"-";
        }
        }

    }
    for (fill = 2; fill < COLUMNS && raw != snakey && raw != appley; fill++){  //Draw raw without noting
        cout<<"-";
    }
    cout<<"*\n";
}
drawBorder();
}

void drawBorder(int score,int sx,int sy,int ax,int ay){     // Draw border with score and cords
    for (int i = 0; i < COLUMNS; i++){
        cout<<"*";
    }
    cout<<"\tscore: "<<score<<" x,y "<<sx<<" "<<sy<<" "<<ax<<" "<<ay<<endl;
}
void drawBorder(){      //Draw only border
    for (int i = 0; i < COLUMNS; i++){
        cout<<"*";
    }
    cout<<endl;
}