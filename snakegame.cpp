#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
bool gameover;
const int hei = 25;
const int wid = 25;
int x, y, fruitX, fruitY, score;
struct Snake
{int x, y;} s[100];
bool noprint = false;
bool fruit_timer;
int tailX[100];
int tailY[100];
int tailLen;
enum eDirection { Stop = 0, LEFT, RIGHT, DOWN, UP };
eDirection dir;
int ntail = 4 ;
int randx, randy;
int tailfposx, tailfposy, tailsposx, tailsposy;
int tail2x, tail2y;
bool moved = false;
void randxy() {
    randx = (rand() % wid) - 1;
    randy = (rand() % wid) - 1;
}
void init() {
    //initializing the game
    srand(time(NULL));
    gameover = false;
    score = 0;
    dir = Stop;
    x = wid / 2;
    y = hei / 2;
    anchor:
    randxy();
    if (randx != 0 && randx != wid && randy != 0 && randy != wid && randx != -1 && randy != -1) {
        fruitX = randx;
        fruitY = randy;
    }
    else {
        goto anchor;
    }
}
void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT) {
                dir = LEFT;
            }
            break;
        case 'd':
            if (dir != LEFT) {
                dir = RIGHT;
            }
            break;
        case 'w':
            if (dir != DOWN) {
                dir = UP;
            }
            break;
        case 's':
            if (dir != UP) {
                dir = DOWN;
            }
            break;
        case 'x':
            gameover = true;
            break;
        }
    }

}
void fruittimer() {
    if (fruit_timer) {
        Sleep(1000);
        fruitX = (rand() % wid) - 1;
        fruitY = (rand() % hei) - 1;
    }
    }
void drawing()
{
    if (!gameover) { system("cls"); }
    cout << "The game will stop when you hit your tail." << endl;
    for (int i = 0; i < wid + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < hei; i++)
    {
        for (int j = 0; j < wid; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else
            {
                bool print = false;
                for (int k = 0; k < ntail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }


            if (j == wid - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < wid + 2; i++)
        cout << "#";
    cout << endl;
    cout << "SCORE:" << score << endl;
}
void cog() {
    int fx = tailX[0];
    int fy = tailY[0];
    int smemx, smemy;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < ntail; i++) {
        smemx = tailX[i];
        smemy = tailY[i];
        tailX[i] = fx;
        tailY[i] = fy;
        fx = smemx;
        fy = smemy;
    }   
    switch (dir)
    {
    case LEFT:
        dir;
        x--;
        moved = true;
        break;
    case RIGHT:
        x++;
        moved = true;
        break;
    case UP:
        y--;
        moved = true;
        break;
    case DOWN:
        y++;
        moved = true;
        break;
    case 'x':
        gameover = true;
        break;
    }
    if (x > wid - 1) { x = 0; }
    if (x < 0) { x = wid - 1; }
    if (y > hei - 1) { y = 0; }
    if (y < 0) { y = hei - 1; }
    if (x == fruitX && y == fruitY) {
        score += 10;
        anchor:
        randxy();
        if (randx != 0 && randx != wid && randy != 0 && randy != wid && randx != -1 && randy != -1) {
            fruitX = randx;
            fruitY = randy;
        }
        else {
            goto anchor;
        }
        ntail++;
        fruit_timer = false;
    }
    for (int i = 0; i < ntail; i++) {
        if (tailX[i] == x && tailY[i] == y && moved) {
            gameover = true;
            cout << "You died!" << endl;
            system("pause");
        }
        else {
            gameover = false;
        }
    }
    Sleep(60);
}

int main() {
    init();
    while (!gameover) {
        drawing();
        input();
        cog();
    }
    while (gameover) {
        system("cls");
        cout << "You hit your tail!" << endl;
        Sleep(3000);
    }
    return 0;
}