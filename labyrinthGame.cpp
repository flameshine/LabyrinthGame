#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int ROWS = 15;
const int COLUMNS = 25;
const int WALL = 1;
const int SPACE = 0;

int arr_one[ROWS][COLUMNS] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1},
	{1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1},
	{1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,1},
	{1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,0,1},
	{1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,1,1,1,1,1},
	{1,0,1,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,0,0,1,1,1,1,0,1},
	{1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,0,0,0,0,1,0,1},
	{1,0,1,0,0,0,0,0,0,1,0,1,0,0,0,0,1,0,1,0,1,1,1,0,1},
	{1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,1,0,1},
	{1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int arr_two[ROWS][COLUMNS] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,1,0,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,0,0,0,1,0,1,1,1,0,1,1,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1},
	{1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,1},
	{1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,0,1,0,1,1,1,0,0,0,1},
	{1,1,1,1,0,1,1,1,1,0,0,0,0,0,1,0,1,1,1,0,1,0,1,1,1},
	{1,0,0,0,0,0,0,0,1,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,0,0,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,1,0,1,0,1,1,1,1,1,1,0,1,1,0,0,0,0,0,1},
	{1,0,1,1,1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,1},
	{1,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1},
	{1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,1,1,0,1,0,1},
	{1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int arr_three[ROWS][COLUMNS] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,0,1},
	{1,1,1,1,1,1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,1},
	{1,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,0,0,1,0,0,1},
	{1,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1},
	{1,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,1,1,1,1,1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,1,0,1},
	{1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,1},
	{1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,1},
	{1,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1},
	{1,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,1},
	{1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,1,1,1,1,0,1},
	{1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void SetColor(int text, int background);
void SetCursorFlag(bool flag);
void ChangeLevelToSecond();
void ChangeLevelToThird();
void ShowLabyrinth();
void ShowInfo(int coin_counter, int lvl);

int GenerateCoins(int coin_counter, int coin);

enum ConsoleColor;

int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(NULL));

	SetCursorFlag(false);

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	time_t start;
	time_t end;
	
	bool game = true;
	bool lvl_two = true;
	bool lvl_three = true;

	int lvl = 1;

	time(&start);


	while (game == true)
	{
		COORD coord;
		COORD ShowRemainCoins;
		COORD exit;
		COORD counter;
		COORD level;

		counter.Y = 2;
		counter.X = 26;
		level.Y = 0;
		level.X = 26;

	        int coin = 3 + rand() % 7;
		int coin_counter = 0;

		coin_counter = GenerateCoins(coin_counter, coin);

		bool flag = true;
		bool play = true;

		coord.X = 1 + rand() % 23;
		coord.Y = 1 + rand() % 13;

		arr_one[coord.Y][coord.X] = 3;

		GenerateCoins(coin_counter, coin);
		ShowLabyrinth();
		ShowInfo(coin_counter, lvl);

		while (flag == true)
		{
			int number = _getch();

			if (number == 224)
			{
				number = _getch();

				if (number == 72)
				{
					if (arr_one[coord.Y - 1][coord.X] != WALL)
					{
						SetConsoleCursorPosition(handle, coord);
						SetColor(15, 0);
						cout << " ";
						coord.Y--;
						SetConsoleCursorPosition(handle, coord);
						SetColor(10, 0);
						cout << "X";
					}
				}

				else if (number == 77)
				{
					if (arr_one[coord.Y][coord.X + 1] != WALL)
					{
						SetColor(15, 0);
						SetConsoleCursorPosition(handle, coord);
						cout << " ";
						coord.X++;
						SetConsoleCursorPosition(handle, coord);
						SetColor(10, 0);
						cout << "X";
					}
				}

				else if (number == 75)
				{
					if (arr_one[coord.Y][coord.X - 1] != WALL)
					{
						SetColor(15, 0);
						SetConsoleCursorPosition(handle, coord);
						cout << " ";
						coord.X--;
						SetConsoleCursorPosition(handle, coord);
						SetColor(10, 0);
						cout << "X";
					}
				}

				else if (number == 80)
				{
					if (arr_one[coord.Y + 1][coord.X] != WALL)
					{
						SetColor(15, 0);
						SetConsoleCursorPosition(handle, coord);
						cout << " ";
						coord.Y++;
						SetConsoleCursorPosition(handle, coord);
						SetColor(10, 0);
						cout << "X";
					}
				}

				if (arr_one[coord.Y][coord.X] == 8)
				{
					coin_counter--;
					SetColor(15, 0);
					SetConsoleCursorPosition(handle, counter);
					cout << "Осталось монет до открытия выхода: " << coin_counter;
					arr_one[coord.Y][coord.X] = SPACE;
				}

				if (coin_counter == 0 && play == true)
				{
					exit.X = 1 + rand() % 23;
					exit.Y = 1 + rand() % 13;
					arr_one[exit.Y][exit.X] = 7;
					SetConsoleCursorPosition(handle, exit);
					SetColor(0, 14);
					cout << " ";

					play = false;
				}

				if (arr_one[coord.Y][coord.X] == 7)
					lvl++;
			}

			if (lvl == 2 && lvl_two == true)
			{
				ChangeLevelToSecond();

				system("cls");

				lvl_two = false;

				flag = false;
			}

			if (lvl == 3 && lvl_three == true)
			{
				ChangeLevelToThird();

				system("cls");

				lvl_three = false;

				flag = false;
			}

			if (lvl == 4)
			{
				flag = false;

				game = false;

				break;
			}
		}
	}

	time(&end);

	double seconds = difftime(end, start);

	COORD off;

	off.Y = 4;
	off.X = 26;

	SetConsoleCursorPosition(handle, off);
	SetColor(15, 0);
	cout << "Время прохождения: " << seconds << " секунд(ы)!" << endl;

	off.Y = 17;
	off.X = 0;
	SetConsoleCursorPosition(handle, off);

	system("pause");

	return NULL;
}

void ShowLabyrinth()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{
			if (arr_one[i][j] == WALL)
			{
				SetColor(0, 4);
				cout << " ";
			}

			else if (arr_one[i][j] == SPACE)
			{
				SetColor(15, 0);
				cout << " ";
			}

			else if (arr_one[i][j] == 3)
			{
				SetColor(10, 0);
				cout << "X";
			}

			else if (arr_one[i][j] == 8)
			{
				SetColor(14, 0);
				cout << "*";
			}
		}

		cout << endl;
	}
}

void ShowInfo(int coin_counter, int lvl)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD counter;
	COORD level;

	counter.Y = 2;
	counter.X = 26;
	level.Y = 0;
	level.X = 26;

	SetConsoleCursorPosition(handle, level);
	SetColor(15, 0);
	cout << "Уровень: " << lvl;
	SetConsoleCursorPosition(handle, counter);
	cout << "Осталось монет до открытия выхода: " << coin_counter;
}

void ChangeLevelToThird()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
			arr_one[i][j] = arr_two[i][j];
	}
}

void ChangeLevelToSecond()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
			arr_one[i][j] = arr_two[i][j];
	}
}

void SetCursorFlag(bool flag)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(handle, &info);
	info.bVisible = flag;
	GetConsoleCursorInfo(handle, &info);
}

void SetColor(int text, int background)
{
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(StdOut, (WORD)((background << 4) | text));
}

int GenerateCoins(int coin_counter, int coin)
{
	COORD ShowRemainCoins;

	while (coin_counter <= coin)
	{
		ShowRemainCoins.Y = 1 + rand() % 13;
		ShowRemainCoins.X = 1 + rand() % 23;

		if (arr_one[ShowRemainCoins.Y][ShowRemainCoins.X] == SPACE)
		{
			arr_one[ShowRemainCoins.Y][ShowRemainCoins.X] = 8;
			coin_counter++;
		}
	}

	return coin_counter;
}

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};
