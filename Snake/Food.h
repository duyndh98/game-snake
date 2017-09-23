#ifndef _FOOD_H
#define _FOOD_H

#include "Noname.h"
#include "Point.h"
#include "Map.h"
#include "Snake.h"

class Food :public Point
{
private:
	
public:
	Food(Map *map)
	{
		_color = C_FOOD;
		_symbol = S_FOOD;
	
		COORD p;
		do
		{
			p = { random(0, map->getSize().X - 1), random(0, map->getSize().Y - 1) };
		} while (map->getCellOfBoard(p) != MS_FLOOR);
		_position = p;
		map->setCellOfBoard(p, _symbol);
	}
};

class BonusFood :public Point
{
private:
	short _lifeTimeRemain;

public:
	//const char COLOR = C_FOOD;

	BonusFood(Map *map, Snake *player)
	{
		_color = C_FOOD;
		_lifeTimeRemain = (map->getSize().X + map->getSize().Y) * 2 / 3.0;

		COORD p;
		do
		{
			p = { random(0, map->getSize().X - 2), random(0, map->getSize().Y - 2) };
		} while (map->getCellOfBoard(p) != MS_FLOOR
			|| map->getCellOfBoard({ p.X + 1, p.Y }) != MS_FLOOR
			|| map->getCellOfBoard({ p.X, p.Y + 1 }) != MS_FLOOR
			|| map->getCellOfBoard({ p.X + 1, p.Y + 1 }) != MS_FLOOR
			);
		
		_position = p;

		map->setCellOfBoard(p, SI_BFOOD);
		map->setCellOfBoard({ p.X + 1, p.Y }, SI_BFOOD);
		map->setCellOfBoard({ p.X, p.Y + 1 }, SI_BFOOD);
		map->setCellOfBoard({ p.X + 1, p.Y + 1 }, SI_BFOOD);
	}

	void show();

	void hide();

	void decreaseLifeTime();

	bool isAlive();
};

#endif // !_FOOD_H