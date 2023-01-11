// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameOver;
bool update = true;
const int height = 20;
const int width = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum Direction {STOP = 0,LEFT,RIGHT,UP,DOWN};
Direction dir;
int upd = 0;
int updDist = 210;
void Setup() {
    
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    
    
}
void Draw() {
    system("cls");
    
    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                cout << "#";
            }
            if(i==y && j==x){
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "@";
            }
            else { 
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }

                }
                if (!print) {
                    cout << " ";
                }
            
            }
            if (j == width-1) {
                cout << "#";
            }
            
        }
        
        cout << endl;
    }






    for (int i = 0; i < width+2; i++) {
        cout << "#";
    }

    upd += 1;
    cout << endl << "Score: " << score<< endl << "UpdateCount: " << upd << endl << "Using CaesiumLite";

}
void Input() {
    if (_kbhit()) {
        switch (_getch())
        {
        case'a':
            dir = LEFT;
            break;
        case'd':
            dir = RIGHT;
            break;
        case'w':
            dir = UP;
            break;
        case's':
            dir = DOWN;
            break;
        case'x':
            gameOver=true;
            break;
        }
    }

}
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prevToX, prevToY;
    for (int i = 1; i < nTail;i++) {
        prevToX = tailX[i];
        prevToY = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prevToX;
        prevY = prevToY;
        

    }
    tailY[0] = y;
    tailX[0] = x;
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }



    if (x == fruitX && y == fruitY) {
        nTail++;
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }


    








    if (x > width-1 || x < 0 || y > height - 1 || y < 0)gameOver = true;
    
}
void TriggerLoop() {
    Sleep(updDist);
    update = true;
    
    
}
int main()
{
    cout << "USING CAESIUM LITE\n";
    Setup();
    while (!gameOver) {
        if(update)Draw();
        Input();
        Logic();
        

        


        update=false;
        TriggerLoop();
        
    }
    if(gameOver)return 0;
}


