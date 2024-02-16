#include<iostream>
#include<cstdlib> 
#include<conio.h>
#include<time.h>
#include <Windows.h>
using namespace std;
//the variables:
int MapX, MapY;
int SnakeX , SnakeY;
int tailx[50], tailY[50],tailN; 
int foodX, foodY;
int Score = 0;
char dir;
int sdir=1; //the stable direction
int delay = 150;//the speed when the game starte
bool gameover = false;

void theinstructions() {
	cout << "THE SNAKE GAME 2:" << endl;
	cout << "Use awsd buttons to control the snake " << endl << "*press x to exit the game while playing*";
	cout << endl << "press s to start the game";

}//some inctructions for the user befor start the game

void shiftR(int arr[], int size) {
	for (int i = size - 2; i >= 0; i--)
		arr[i + 1] = arr[i];
}
//to move the tail
void setgnd() {
	MapX = 60;
	MapY = 20;
	srand(time(NULL));
		foodX =1+ rand() %(MapX-2) ;//a value btween 1 and 39
		foodY = 1+rand() %(MapY-2) ;//a value btween 1 and 19
		SnakeX = MapX/2;//in the middle of the map
		SnakeY = MapY / 2;

	}

void dsply() {
	system("cls");
	for (int i = 0; i < MapY; i++) {
		for (int j = 0; j < MapX; j++) {


			if (i == 0 || i == (MapY - 1))//the wall width
				cout << "#";

			else if (j == 0 || j == (MapX - 1))//the wall lenth
				cout << "#";

			else if (i == SnakeY && j == SnakeX)//the snake
				cout << "O";
			else if (i == foodY && j == foodX)//the food
				cout << "$";
			else {
				bool printed = false;
				for (int z = 0; z < tailN; z++) {
					if (tailx[z] == j && tailY[z] == i) {
						cout << "x";
						printed = true;
						break;
					}
				}
				if (!printed)
					cout << " ";
			}
		}
		cout << endl;
	}
	if (SnakeX == 0 || SnakeX == (MapX - 1)|| SnakeY == 0 || SnakeY == (MapY - 1)) //to lose when hit the wall
		gameover = true;
	
	if (SnakeX == foodX && SnakeY == foodY) {
		foodX = 1 + rand() % (MapX - 2);
		foodY = 1 + rand() % (MapY - 2);
		Score++;
		tailN++;
		delay -= 4;//to increase the speed every time the snake eat an apple
	}
	cout << endl << "Score:" << Score << endl;


	}
//to use aswd buttons to controle the direction
void ctrl() {
	if (_kbhit()) {
		dir = _getch();
		switch (dir) {
		case 'a':
			sdir = 1;
			break;
		case 'd':
			sdir=2;
			break;
		case 'w':
			sdir=3;
			break;
		case 's':
			sdir=4;
			break;
		case 'x':
			sdir = 5;
			break;
		}}}
//to stabilizing the movement direction
void move() {
	shiftR(tailx, 50);
	shiftR(tailY, 50);
	tailx[0] = SnakeX;
	tailY[0] = SnakeY;

	switch (sdir) {
	case 1:
		SnakeX--;
		break;
	case 2:
		SnakeX++;
		break;
	case 3:
		SnakeY--;
		break;
	case 4:
		SnakeY++;
		break;
	case 5:
		system("cls");
		exit(5) ;
	}
}

void endthegame() {
	system("cls");
	for (int i = 0; i < MapY; i++) {
		for (int j = 0; j < MapX; j++) {


			if (i == 0 || i == (MapY - 1))//the wall width
				cout << "#";

			else if (j == 0 || j == (MapX - 1))//the wall lenth
				cout << "#";

			else if (i == 10 && j == 20)
				cout << "game over :(";

			else
				cout << " ";

		}
		cout << endl;
	}

}

void main() {
	theinstructions();
	if (_getch() == 's') {
		setgnd();
		while (!gameover) {
			dsply();
			ctrl();
			move();
			Sleep(delay);//a single fram in ("delay") milisecond
		}
		endthegame();
	}
}
