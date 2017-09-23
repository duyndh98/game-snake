#ifndef _FILE_H
#define _FILE_H

#include "Noname.h"
#include "Map.h"
#include "Snake.h"

// this function get map and snake info from a map file 
static void getMapFile(string sf, Map *&map, Snake *&snake)
{
	fstream f;
	f.open(sf, ios::in);
	
	short x, y;
	
	char snakeDirection = 0;
	COORD snakeHeadPosition = { 0, 0 };
	
	map = new Map(f, snakeDirection, snakeHeadPosition);
	
	snake = new Snake(f, snakeDirection, snakeHeadPosition);

	// sign snake in map board
	for (list<Point>::iterator iComponents = snake->getComponents()->begin(); iComponents != snake->getComponents()->end(); iComponents++)
		map->setCellOfBoard(iComponents->getPosition(), SI_SNAKE);
		
	f.close();
}

#endif // _FILE_H