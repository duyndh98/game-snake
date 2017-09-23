#include "Snake.h"

void Snake::setComponents(listPoint *pComp) 
{
	_components = pComp;
}

listPoint* Snake::getComponents()
{
	return _components;
}

void Snake::move(char newDir, Map *map, short &eat)
{
	// calculation new head position
	COORD newPos = _components->front().getPosition();
	
	newPos.X += DIF_POS[newDir].X;
	newPos.Y += DIF_POS[newDir].Y;

	// over range of board -> reverse
	if (newPos.X < 0)
		newPos.X = map->getSize().X - 1;
	if (newPos.X >= map->getSize().X)
		newPos.X = 0;

	if (newPos.Y < 0)
		newPos.Y = map->getSize().Y - 1;
	if (newPos.Y >= map->getSize().Y)
		newPos.Y = 0;

	// lost
	if (	map->getCellOfBoard(newPos) == MS_WALL
		||	map->getCellOfBoard(newPos) == SI_SNAKE)
		_alive = false;
	else
	{
		switch (map->getCellOfBoard(newPos))
		{
		case SI_FOOD:
			eat = 1;
			break;
		case SI_BFOOD:
			eat = 2;
			break;
		default:
			// move tail
			// remove old tail
			map->setCellOfBoard(_components->back().getPosition(), MS_FLOOR);
			_components->back().hide();
			_components->pop_back();

			// change new tail symbol
			switch (_components->back().getSymbol())
			{
			case S_VVER:
				_components->back().setSymbol(S_VER);
				break;
			case S_HHOR:
				_components->back().setSymbol(S_HOR);
				break;
			case S_UULL:
				_components->back().setSymbol(S_UL);
				break;
			case S_UURR:
				_components->back().setSymbol(S_UR);
				break;
			case S_DDLL:
				_components->back().setSymbol(S_DL);
				break;
			case S_DDRR:
				_components->back().setSymbol(S_DR);
				break;
			}
			_components->back().show();
		}

		// change head symbol before move
		_components->front().setSymbol(getSymbolByDirection(_direction, newDir));
		_components->front().setColor(SC_BODY);
		_components->front().show();
		
		// move head
		Point p;
		p.setPosition(newPos);
		p.setSymbol(SS_HEAD);
		p.setColor(SC_HEAD);
		_components->push_front(p);

		map->setCellOfBoard(_components->front().getPosition(), SI_SNAKE);
		_components->front().show();
		
		// set new direction
		_direction = newDir;
	}
}

void Snake::show()
{
	for (listPoint::iterator iComponents = _components->begin(); iComponents != _components->end(); iComponents++)
		iComponents->show();
}

char Snake::getDirection()
{
	return _direction;
}

short Snake::getLength()
{
	return _length;
}

bool Snake::isAlive()
{
	return _alive;
}