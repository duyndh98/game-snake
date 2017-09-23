#ifndef _MAP_H
#define _MAP_H

#include "Noname.h"
#include "Point.h"
#include "Snake.h"

class Map
{
private:
	COORD _size;

	Vec2DChar *_board;

public:

	const COORD FRAME_POS = { 3, 9 };

	Map()
	{
		_board = NULL;
	}

	Map(istream& is, char &snakeDir, COORD &snakeHeadPos)
	{
		short x, y;
		
		// set map board
		_board = new Vec2DChar;
		
		string s;
		short i = 0;
		while (getline(is, s))
		{
			vector<char> *row = new vector<char>;
			
			for (short j = 0; j < s.size(); j++)
			{
				if (s[j] == SI_SNAKE_LEFT || s[j] == SI_SNAKE_RIGHT)
				{
					x = i;
					y = j;
					snakeDir = s[j];
				}
				row->push_back(exchange(s[j]));
			}
			_board->push_back(*row);
			i++;
		}
		_size = { (short)_board->size(), (short)(*_board)[0].size() };
		snakeHeadPos = { x, y };
	}

	~Map()
	{
		if (_board != NULL)
		{
			delete _board;
			_board = NULL;
		}
	}

	COORD getSize();
	
	void setSize(COORD);
	
	void setBoard(Vec2DChar *);
	
	void setCellOfBoard(COORD, char);

	char getCellOfBoard(COORD);

	Vec2DChar* getBoard();
	
	void show();
};

#endif // !_MAP_H
