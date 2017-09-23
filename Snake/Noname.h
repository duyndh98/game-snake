#ifndef _NONAME_H
#define _NONAME_H

using namespace std;

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

static HANDLE outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
static HANDLE inpHandle = GetStdHandle(STD_INPUT_HANDLE);

const COORD DIF_POS[] = { {0, -1}, {-1, 0}, {0, 1}, {1, 0} };

typedef vector<vector<char>> Vec2DChar;

enum KeyPress
{
	K_LEFT = -75,
	K_RIGHT = -77,
	K_UP = -72,
	K_DOWN = -80,
	K_ESC = 27,
	K_ENTER = 13,
	
	K_a = 97,
	K_A = 65,
	K_w = 119,
	K_W = 87,
	K_d = 100,
	K_D = 68,
	K_s = 115,
	K_S = 83,
	K_p = 112,
	K_P  = 80,
};

enum Symbol
{
	S_FILL = -37,
	S_BRICK = -78,
	S_SQUARE = -2,
	S_CIRCLE = 111,
	S_SPACE = 32,

	S_UULL = -55,
	S_UURR = -69,
	S_DDLL = -56,
	S_DDRR = -68,

	S_UL = -38,
	S_UR = -65,
	S_DL = -64,
	S_DR = -39,

	S_VVER = -51,
	S_HHOR = -70,

	S_VER = -60,
	S_HOR = -77,

	S_SMALLER = 60,
	S_BIGGER = 62,
	S_STAR = 42,
	S_SHARP = 35,
	S_o = 111,
	S_O = 79,
};

enum Color
{
	C_BLACK = 0,
	C_BLUE = 1,
	C_GREEN = 2,
	C_AQUA = 3, 
	C_RED = 4,
	C_PURPLE = 5, 
	C_YELLOW = 6,
	C_WHITE = 7,
	C_GRAY = 8, 
	C_LIGHT_BLUE = 9,
	C_LIGHT_GREEN = 10,
	C_LIGHT_AQUA = 11,
	C_LIGHT_RED = 12,
	C_LIGHT_PURPLE = 13,
	C_LIGHT_YELLOW = 14,
	C_LIGHT_WHITE = 15
};

enum Direction
{
	D_LEFT = 0,
	D_UP = 1,
	D_RIGHT = 2,
	D_DOWN = 3
};

enum SignInMap
{
	SI_FLOOR = S_SPACE,	
	SI_WALL = S_SHARP,

	// in Map file
	SI_SNAKE_LEFT = S_SMALLER,
	SI_SNAKE_RIGHT = S_BIGGER,
	
	// in Map board
	SI_SNAKE = S_STAR,  
	SI_FOOD = S_o, 
	SI_BFOOD = S_O,
};

enum SnakeConsts
{
	SS_HEAD = S_SQUARE,
	SC_HEAD = C_BLUE,
	
	SC_BODY = C_BLACK
};

enum BoardConsts
{
	MS_WALL = S_BRICK,
	MC_WALL = C_LIGHT_WHITE,

	MS_FLOOR = S_FILL,
	MC_FLOOR = C_WHITE
};

enum ObjectConsts
{
	S_FOOD = S_CIRCLE,
	C_FOOD = C_RED,
	
	C_SCORE = C_LIGHT_YELLOW
};

static inline short random(short low, short high)
{
	return (low + rand() % (high - low + 1));
}

static char exchange(char &c)
{
	switch (c)
	{
	case SI_WALL:	
		c = MS_WALL;
		break;
	default:
		c = MS_FLOOR;
		break;
	}	
	return c;
}

static void resizeConsole(int width, int height)
{
	_COORD coord;
	coord.X = width;
	coord.Y = height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = height - 1;
	Rect.Right = width - 1;

	SetConsoleScreenBufferSize(outHandle, coord);
	SetConsoleWindowInfo(outHandle, TRUE, &Rect);
}

static inline void gotoxy(COORD p)
{
	swap(p.X, p.Y);
	SetConsoleCursorPosition(outHandle, p);
}

static inline void setColor(int colorText, int colorBackground)
{
	SetConsoleTextAttribute(outHandle, colorText + 16 * colorBackground);
}

template <class T>
static inline void print(COORD p, T s, char teColor, char bgColor)
{
	setColor(teColor, bgColor);
	gotoxy(p);
	cout << s;
}

static void hideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(outHandle, &info);
}

static short readKey()
{
	fflush(stdin);
	short c = _getch();
	if (c == 224)
	{
		c = _getch();
		return -c;
	}
	else
		return c;
}

static char getSymbolByDirection(char oldDir, char newDir)
{
	if (newDir == oldDir)
	{
		if (oldDir % 2)
			return S_HHOR;
		else
			return S_VVER;
	}
	if ((oldDir == D_UP && newDir == D_RIGHT) || (oldDir == D_LEFT && newDir == D_DOWN))
		return S_UULL;
	if ((oldDir == D_UP && newDir == D_LEFT) || (oldDir == D_RIGHT && newDir == D_DOWN))
		return S_UURR;
	if ((oldDir == D_DOWN && newDir == D_RIGHT) || (oldDir == D_LEFT && newDir == D_UP))
		return S_DDLL;
	if ((oldDir == D_DOWN && newDir == D_LEFT) || (oldDir == D_RIGHT && newDir == D_UP))
		return S_DDRR;
}

#endif // !_NONAME_H