#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
using namespace std;

bool stop_game;
const int width = 40; 
const int height = 20;
int x, y, fruitX, fruitY, score; 
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; 
eDirection dir;
int tailX[50], tailY[50];
int length_of_tail;

void setup()
{
    stop_game = false; 
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width; 
    fruitY = rand() % height;
    int score = 0;

}

void appearance()
{
    system("cls");
    cout << "Welcome to A Snake Game" << endl;

    for (int i = 0; i < width + 2; i++) 
    {
        cout << "-";
    }
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "|";
            }

            if (i == y && j == x)
            {
                cout << "0";
            }
            else if (i == fruitY && j == fruitX)
            {
                cout << "*";

            }
            else
            {
                bool print = false;
                for (int k = 0; k < length_of_tail; k++)
                {

                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                    

                }
                if (!print)
                {
                    cout << " ";
                }

            }



            if (j == width - 1) 
            {
                cout << "|";
            }

        }
        cout << endl; 

    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Your Current Score : " << score << endl;
}

void click()
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
        default:
            break;
        }
    }

}

void logic()
{
    int previous_X = tailX[0];
    int previous_Y = tailY[0];
    int previous_2X, previous_2Y;
    tailX[0] = x; 
    tailY[0] = y;


    for (int i = 1; i < length_of_tail; i++) 
    {
        previous_2X = tailX[i];
        previous_2Y = tailY[i];
        tailX[i] = previous_X;
        tailY[i] = previous_Y;
        previous_X = previous_2X;
        previous_Y = previous_2Y;
     
    }

    switch (dir)
    {
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
    if (x > width || x < 0 || y > height || y < 0)
    {
        stop_game = true;

    }
    for (int i = 0; i < length_of_tail; i++)
    {
        if (tailX[i] == x && tailY[i] == y) 
        {
            stop_game = true;
        }
    }
    if (x == fruitX && y == fruitY) 
    {

        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        length_of_tail++;
    }
    if (score == 200)
    {
        stop_game = true;
        cout << setw(25) << "YOU WON!!!" << endl;
    }
    Sleep(100); 
}




int main()
{

    setup();

    while (!stop_game)
    {
        appearance();
        click();
        logic();

    }

}