#include "Score.h"

void Score::increaseScore(short x)
{
	_s += x;
}

long Score::getScore()
{
	return _s;
}

void Score::show()
{
	print({ FRAME_POS.X + 2, FRAME_POS.Y }, _s, _color, C_BLACK);
}