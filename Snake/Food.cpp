#include "Food.h"

void BonusFood::show()
{
	print({ _position.X + FRAME_POS.X, _position.Y + FRAME_POS.Y }, (char)S_UL, _color, _bgColor);
	print({ _position.X + FRAME_POS.X, _position.Y + 1 + FRAME_POS.Y }, (char)S_UR, _color, _bgColor);
	print({ _position.X + 1 + FRAME_POS.X, _position.Y + FRAME_POS.Y }, (char)S_DL, _color, _bgColor);
	print({ _position.X + 1 + FRAME_POS.X, _position.Y + 1 + FRAME_POS.Y }, (char)S_DR, _color, _bgColor);
}

void BonusFood::hide()
{
	print({ _position.X + FRAME_POS.X, _position.Y + FRAME_POS.Y }, (char)S_UL, _bgColor, _bgColor);
	print({ _position.X + FRAME_POS.X, _position.Y + 1 + FRAME_POS.Y }, (char)S_UR, _bgColor, _bgColor);
	print({ _position.X + 1 + FRAME_POS.X, _position.Y + FRAME_POS.Y }, (char)S_DL, _bgColor, _bgColor);
	print({ _position.X + 1 + FRAME_POS.X, _position.Y + 1 + FRAME_POS.Y }, (char)S_DR, _bgColor, _bgColor);
}

void BonusFood::decreaseLifeTime()
{
	_lifeTimeRemain--;
}

bool BonusFood::isAlive()
{
	return _lifeTimeRemain;
}
