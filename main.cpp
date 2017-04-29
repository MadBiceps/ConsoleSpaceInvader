#include <iostream>
#include <Windows.h>
#include "time.h"


using namespace std;

char Map[20][20] = {
	"###################",
	"#                 #",
	"#  @ @ @ @ @ @ @  #",
	"#   @ @ @ @ @ @   #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#        W        #",
	"###################"
};

bool endgame = false;
int gamespeed = 50;
int randomNum;
int maxHealth=200;
int yourHealth=maxHealth;

int main()
{
	system("color 0a");
	while (endgame == false)
	{
		srand(time(0));
		system("cls");

		for (int y = 0; y < 20; y++)
		{
			cout << Map[y] << endl;
		}

		cout << "Health " << yourHealth << " / " << maxHealth;

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				switch (Map[y][x])
				{
				case'W': {
					if ()
					{
						int newX = x - 1;
						
						switch(Map[y][newX])
						{
						case' ':
						{
							Map[y][x] = ' ';
							x--;
							Map[y][newX] = 'W';
							break;
						}
						}
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						int newX = x + 1;

						switch (Map[y][newX])
						{
						case' ':
						{
							Map[y][x] = ' ';
							x++;
							Map[y][newX] = 'W';
						}
						}
					}

					if (GetAsyncKeyState(VK_SPACE))
					{
						y--;
						Map[y][x] = '^';


					}
					break;

				case'^':
				{
					Map[y][x] = ' ';
					y--;

					if (Map[y][x]!='#'&&Map[y][x]!='@')
					{
						Map[y][x] = '^';
					}
					else 
					{
						if (Map[y][x] == '@')
						{
							Map[y][x] = ' ';
						}
					}
					break;
				}
				break;

				case'@': {
					randomNum = rand() % 10 + 1;
					if (randomNum == 1)
					{
						y++;
						Map[y][x] = '*';
					}

					break;

				case'*': {

					Map[y][x] = ' ';
					y++;

					if (Map[y][x]!='#'&&Map[y][x]!='W')
					{
						Map[y][x] = '*';
					}
					else
					{
						if (Map[y][x]=='W')
						{
							yourHealth -= 20;

						}
					}

					break;
				}
				}
				}

				}

			}
		}

		if (yourHealth<=0)
		{
			endgame = true;


		}

		Sleep(gamespeed);
	}

	system("cls");
	cout << "You lost" << endl;

	system("pause");

	return 0;
}