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

enum color
{
	BLACK = 0,
	RED = 4,
	LIGHT_GREEN = 10,
	YELLOW = 14,
	WHITE = 15
};

int array_one[ROWS][COLUMNS] =
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

int array_two[ROWS][COLUMNS] =
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

int array_three[ROWS][COLUMNS] =
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

void set_color(int text, int background);
void set_cursor_flag(bool flag);
void switch_level_to_second();
void switch_level_to_third();
void show();
void show_information(int coin_counter, int lvl);

int generate_coins(int coin_counter, int coin);

int main()
{
	srand(time(NULL));

	set_cursor_flag(false);

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	time_t start_time;
	time_t end_time;
	
	bool game = true;
	bool is_lvl_two = true;
	bool is_lvl_three = true;

	int lvl = 1;

	time(&start_time);

	while (game == true)
	{
		COORD player_position;
		COORD portal_position;
		COORD counter_position;
		COORD level_position;

		counter_position.Y = 2;
		counter_position.X = 26;
		level_position.Y = 0;
		level_position.X = 26;

	    int coin = 3 + rand() % 7;
		int coin_counter = 0;

		coin_counter = generate_coins(coin_counter, coin);

		bool flag = true;
		bool play = true;

		player_position.X = 1 + rand() % 23;
		player_position.Y = 1 + rand() % 13;

		array_one[player_position.Y][player_position.X] = 3;

		generate_coins(coin_counter, coin);
		show();
		show_information(coin_counter, lvl);

		while (flag == true)
		{
			int number = _getch();

			if (number == 224)
			{
				number = _getch();

				if (number == 72)
				{
					if (array_one[player_position.Y - 1][player_position.X] != WALL)
					{
						SetConsoleCursorPosition(handle, player_position);
						set_color(WHITE, BLACK);
						cout << " ";
						--player_position.Y;
						SetConsoleCursorPosition(handle, player_position);
						set_color(LIGHT_GREEN, BLACK);
						cout << "X";
					}
				}
				else if (number == 77)
				{
					if (array_one[player_position.Y][player_position.X + 1] != WALL)
					{
						set_color(WHITE, BLACK);
						SetConsoleCursorPosition(handle, player_position);
						cout << " ";
						++player_position.X;
						SetConsoleCursorPosition(handle, player_position);
						set_color(LIGHT_GREEN, BLACK);
						cout << "X";
					}
				}
				else if (number == 75)
				{
					if (array_one[player_position.Y][player_position.X - 1] != WALL)
					{
						set_color(WHITE, BLACK);
						SetConsoleCursorPosition(handle, player_position);
						cout << " ";
						--player_position.X;
						SetConsoleCursorPosition(handle, player_position);
						set_color(LIGHT_GREEN, BLACK);
						cout << "X";
					}
				}
				else if (number == 80)
				{
					if (array_one[player_position.Y + 1][player_position.X] != WALL)
					{
						set_color(WHITE, BLACK);
						SetConsoleCursorPosition(handle, player_position);
						cout << " ";
						++player_position.Y;
						SetConsoleCursorPosition(handle, player_position);
						set_color(LIGHT_GREEN, BLACK);
						cout << "X";
					}
				}

				if (array_one[player_position.Y][player_position.X] == 8)
				{
					--coin_counter;
					set_color(WHITE, BLACK);
					SetConsoleCursorPosition(handle, counter_position);
					cout << "Coins left before the portal opens: " << coin_counter;
					array_one[player_position.Y][player_position.X] = SPACE;
				}

				if (coin_counter == 0 && play == true)
				{
					portal_position.X = 1 + rand() % 23;
					portal_position.Y = 1 + rand() % 13;
					array_one[portal_position.Y][portal_position.X] = 7;
					SetConsoleCursorPosition(handle, portal_position);
					set_color(BLACK, YELLOW);
					cout << " ";
					play = false;
				}

				if (array_one[player_position.Y][player_position.X] == 7)
				{
					++lvl;
				}
			}

			if (lvl == 2 && is_lvl_two == true)
			{
				switch_level_to_second();

				system("cls");

				is_lvl_two = false;

				flag = false;
			}

			if (lvl == 3 && is_lvl_three == true)
			{
				switch_level_to_third();

				system("cls");

				is_lvl_three = false;

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

	time(&end_time);

	double seconds = difftime(end_time, start_time);

	COORD result_position;

	result_position.Y = 4;
	result_position.X = 26;

	SetConsoleCursorPosition(handle, result_position);
	set_color(WHITE, BLACK);

	cout << "time spent: " << seconds << " seconds!" << endl;

	result_position.Y = 17;
	result_position.X = 0;

	SetConsoleCursorPosition(handle, result_position);

	system("pause");

	return NULL;
}

void show()
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			if (array_one[i][j] == WALL)
			{
				set_color(BLACK, RED);
				cout << " ";
			}
			else if (array_one[i][j] == SPACE)
			{
				set_color(WHITE, BLACK);
				cout << " ";
			}
			else if (array_one[i][j] == 3)
			{
				set_color(LIGHT_GREEN, BLACK);
				cout << "X";
			}

			else if (array_one[i][j] == 8)
			{
				set_color(YELLOW, BLACK);
				cout << "*";
			}
		}

		cout << endl;
	}
}

void show_information(int coin_counter, int lvl)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD counter_position;
	COORD level_position;

	counter_position.Y = 2;
	counter_position.X = 26;
	level_position.Y = 0;
	level_position.X = 26;

	SetConsoleCursorPosition(handle, level_position);
	set_color(WHITE, BLACK);
	cout << "Level: " << lvl;
	SetConsoleCursorPosition(handle, counter_position);
	cout << "Coins left before the portal opens: " << coin_counter;
}

void switch_level_to_second()
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			array_one[i][j] = array_two[i][j];
		}
	}
}

void switch_level_to_third()
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			array_one[i][j] = array_three[i][j];
		}
	}
}

void set_cursor_flag(bool flag)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(handle, &info);
	info.bVisible = flag;
	GetConsoleCursorInfo(handle, &info);
}

void set_color(int text, int background)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, (WORD) (background << 4) | text);
}

int generate_coins(int coin_counter, int coin)
{
	COORD remaining_coins_position;

	while (coin_counter <= coin)
	{
		remaining_coins_position.Y = 1 + rand() % 13;
		remaining_coins_position.X = 1 + rand() % 23;

		if (array_one[remaining_coins_position.Y][remaining_coins_position.X] == SPACE)
		{
			array_one[remaining_coins_position.Y][remaining_coins_position.X] = 8;
			++coin_counter;
		}
	}

	return coin_counter;
}