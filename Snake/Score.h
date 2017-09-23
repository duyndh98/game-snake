#ifndef  _SCORE_H
#define _SCORE_H

#include "Noname.h"

class Score
{
private:
	long _s;

	char _color;

public:
	const COORD FRAME_POS = { 3, 2 };

	Score()
	{
		_s = 0;
		_color = C_SCORE;
		print(FRAME_POS, "Score ", C_SCORE, C_BLACK);
		print({ FRAME_POS.X + 2, FRAME_POS.Y }, _s, C_SCORE, C_BLACK);
	}

	~Score()
	{
		print(FRAME_POS, "Score ", C_BLACK, C_BLACK);
		print({ FRAME_POS.X + 2, FRAME_POS.Y }, _s, C_BLACK, C_BLACK);
	}

	void increaseScore(short);

	void show();

	void hide();

	long getScore();
};

#endif // ! _SCORE_H