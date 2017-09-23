#include "Point.h"

void Point::setPosition(COORD pp)
{
	_position = pp;
}

COORD Point::getPosition()
{
	return _position;
}

void Point::setSymbol(char c)
{
	_symbol = c;
}

char Point::getSymbol()
{
	return _symbol;
}

void Point::show()
{
	print({ _position.X + FRAME_POS.X, _position.Y + FRAME_POS.Y }, (char)_symbol, _color, MC_FLOOR);
}

void Point::hide()
{
	print({_position.X + FRAME_POS.X, _position.Y + FRAME_POS.Y}, (char)MS_FLOOR, MC_FLOOR, MC_FLOOR);
}

void Point::setColor(char c)
{
	_color = c;
}

char Point::getColor()
{
	return _color;
}