#ifndef _SNAKE_H
#define _SNAKE_H

#include "Noname.h"
#include "Map.h"
#include "Point.h"

class Map; // forward declaration

typedef list<Point> listPoint;

class Snake
{
private:
	
	listPoint *_components;
	
	char _direction;
	
	bool _alive;

	short _length;

	short _speed;

public:
	Snake()
	{
		_direction = D_RIGHT;
		_alive = true;
		_components = NULL;
		_length = 3;
		_speed = 10;
	}

	Snake(istream &is, char snakeDir, COORD snakeHeadPos)
	{
		_alive = true;
		_length = 3;
		_speed = 250;
		switch (snakeDir)
		{
		case SI_SNAKE_LEFT:	
			_direction = D_LEFT;
			break;
		case SI_SNAKE_RIGHT:
			_direction = D_RIGHT;
			break;
		}

		// set snake components
		_components = new listPoint;
		for (short i = _length - 1; i >= 0; i--)
		{
			Point p;
			switch (snakeDir)
			{
			case SI_SNAKE_LEFT:
				p.setPosition({ snakeHeadPos.X, snakeHeadPos.Y + i });
				break;
			case SI_SNAKE_RIGHT:
				p.setPosition({ snakeHeadPos.X, snakeHeadPos.Y - i });
				break;
			}
			// is Head
			if (i == 0)
			{
				p.setSymbol(SS_HEAD);
				p.setColor(SC_HEAD);
			}
			else
			{
				p.setColor(SC_BODY);
				// is tail
				if (i == _length - 1)
					p.setSymbol(S_VER);
				else
					// is body
					p.setSymbol(S_VVER);
			}
			_components->push_front(p);
		}
	}


	~Snake()
	{
		if (_components != NULL)
		{
			delete _components;
			_components = NULL;
		}
	}

	short getSpeed()
	{
		return _speed;
	}

	char getDirection();

	void setComponents(listPoint*);
	
	listPoint *getComponents();

	void show();

	void move(char, Map *, short &);

	short getLength();

	bool isAlive();
};

#endif // !_SNAKE_H