#include "Scene.h"

void PlayScene::run()
{
	_score.show();
	char newDir = _player->getDirection();
	do
	{
		if (_kbhit())
		{
			short key = readKey();
			if (key == K_ESC)
				break;
			switch (key)
			{
			case K_LEFT:
			case K_A:
			case K_a:
				newDir = D_LEFT;
				break;
			case K_UP:
			case K_W:
			case K_w:
				newDir = D_UP;
				break;
			case K_RIGHT:
			case K_D:
			case K_d:
				newDir = D_RIGHT;
				break;
			case K_DOWN:
			case K_S:
			case K_s:
				newDir = D_DOWN;
				break;
			case K_ESC:
			case K_p:
			case K_P:
				
				break;
			}
		}
		
		if (abs(newDir - _player->getDirection()) == 2)
			newDir = _player->getDirection();
		short eat = 0;
		_player->move(newDir, _map, eat);
		switch (eat)
		{
		case 1:
			_score.increaseScore(1);
			_score.show();
			_food->hide();
			//(*map).setCellOfBoard((*food).getPosition(), SI_SNAKE);
			_player->getComponents()->front().show();
			if (_food != NULL)
			{
				delete _food;
				_food = NULL;
			}

			_food = new Food(_map);
			_food->show();
			if (_score.getScore() % 5 == 0 && _bFood == NULL)
			{
				_bFood = new BonusFood(_map, _player);
				_bFood->show();
			}
			break;
		case 2:
			_score.increaseScore(5);
			_score.show();
			_bFood->hide();
			COORD p = _bFood->getPosition();
			_map->setCellOfBoard({ p.X, p.Y }, MS_FLOOR);
			_map->setCellOfBoard({ p.X, p.Y + 1 }, MS_FLOOR);
			_map->setCellOfBoard({ p.X + 1, p.Y }, MS_FLOOR);
			_map->setCellOfBoard({ p.X + 1, p.Y + 1 }, MS_FLOOR);
			_player->getComponents()->front().show();
			if (_bFood != NULL)
			{
				delete _bFood;
				_bFood = NULL;
			}
			break;
		}
		if (_bFood != NULL)
		{
			_bFood->decreaseLifeTime();
			if (_bFood->isAlive() == 0)
			{
				_bFood->hide();
				COORD p = _bFood->getPosition();
				
				_map->setCellOfBoard({ p.X, p.Y }, MS_FLOOR);
				_map->setCellOfBoard({ p.X, p.Y + 1 }, MS_FLOOR);
				_map->setCellOfBoard({ p.X + 1, p.Y }, MS_FLOOR);
				_map->setCellOfBoard({ p.X + 1, p.Y + 1 }, MS_FLOOR);
			
				delete _bFood;
				_bFood = NULL;
			}
		}
		Sleep(_player->getSpeed());
	} while (_player->isAlive());
}

