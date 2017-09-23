#ifndef _POINT_H
#define _POINT_H

#include "Noname.h"

class Point
{
protected:
	COORD _position;
	
	char _color, _bgColor;

	char _symbol;

public:
	const COORD FRAME_POS = { 3, 9 };

	Point()
	{
		_color = C_WHITE;
		_bgColor = MC_FLOOR;
	}

	void setPosition(COORD);

	COORD getPosition();

	void setSymbol(char);

	char getSymbol();

	void show();

	void hide();

	void setColor(char);

	char getColor();
};

#endif // !_POINT_H