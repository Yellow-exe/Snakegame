#include <iostream>
#include <conio.h>
using namespace std;
bool gameover;
const int hei = 10;
const int wid = 10;
int x, y, fruitX, fruitY, score;
bool noprint = false;
enum eDirection { Stop = 0, LEFT, RIGHT, DOWN, UP };
eDirection dir;
void init() {
    //initializing the game
    srand(time(NULL));
    gameover = false;
    score = 0;
    dir = Stop;
    x = wid / 2;
    y = hei / 2;
    //fruitX = (rand() % wid) -1;
    //fruitY = (rand() % hei) -1;
    fruitX = 1;
    fruitY = 1;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void drawing() {
    system("cls");
    fruitX = 1;
    fruitY = 1;
    for (int i = 0; i < wid; i++) {
        cout << "#";
    }
    cout << endl;

    for (int i = 1; i < wid - 1; i++) {
        for (int j = 0; j < hei; j++) {
            if (j == 0) {
                cout << "#";
            }
            else if (fruitY == j && fruitX == i) {
                cout << "X";
            }
            else if (x == i && y == j) {
                cout << "O";
            }
            else if (j == wid - 1) {
                cout << "#";
            }
            else {
                cout << " ";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < wid; i++) {
        cout << "#";
    }
}
void cog() {

}

int main() {
    init();
    while (!gameover) {
        drawing();
    }
    return 0;
}