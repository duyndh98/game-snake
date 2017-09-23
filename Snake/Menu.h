#ifndef _MENU_H
#define _MENU_H

#include "Noname.h"


class Menu
{
private:
	string *_names;
	short _color;

public:	
	const COORD FRAME_POS = { 3, 9 };

	Menu()
	{
		_names = NULL;
		_color = C_WHITE;
	}

	void show();

	void hide();

};

#endif // !_MENU_H
#pragma once
