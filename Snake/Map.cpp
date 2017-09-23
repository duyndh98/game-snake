#include "Map.h"

COORD Map::getSize()
{
	return _size;
}

void Map::setSize(COORD sz)
{
	_size = sz;
}

void Map::setBoard(Vec2DChar *pBoard)
{
	_board = pBoard;
}

void Map::setCellOfBoard(COORD position, char c)
{
	(*_board)[position.X][position.Y] = c;
}

char Map::getCellOfBoard(COORD position)
{
	return (*_board)[position.X][position.Y];
}

Vec2DChar * Map::getBoard()
{
	return _board;
}

void Map::show()
{
	for (short i = 0; i < _size.X; i++)
		for (short j = 0; j < _size.Y; j++)
			switch ((*_board)[i][j])
			{
			case MS_WALL:
				print({ i + FRAME_POS.X, j + FRAME_POS.Y }, (char)MS_WALL, MC_WALL, MC_FLOOR);
				break;
			case MS_FLOOR:
				print({ i + FRAME_POS.X, j + FRAME_POS.Y }, (char)MS_FLOOR, MC_FLOOR, C_BLACK);
				break;
			}
}