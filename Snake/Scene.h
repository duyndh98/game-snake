#ifndef _SCENE_H
#define _SCENE_H

#include "Map.h"
#include "Snake.h"
#include "File.h"
#include "Food.h"
#include "Score.h"

class PlayScene
{
private:
	Score _score;

	Food *_food;

	BonusFood *_bFood;

	Snake *_player;

	Map *_map;

public:
	PlayScene()
	{
		_player = NULL;
		_food = NULL;
		_bFood = NULL;
		_map = NULL;
		_map = NULL;
		_player = NULL;
	}

	PlayScene(string sf)
	{
		_player = NULL;
		_food = NULL;
		_bFood = NULL;
		_map = NULL;
		_map = NULL;
		_player = NULL;

		getMapFile(sf, _map, _player);
		_map->show();

		_food = new Food(_map);
		_food->show();

		_player->show();
	}

	~PlayScene()
	{
		if (_player != NULL)
		{
			delete _player;
			_player = NULL;
		}
		if (_map != NULL)
		{
			delete _map;
			_map = NULL;
		}
		if (_food != NULL)
		{
			delete _food;
			_food = NULL;
		}
		if (_bFood != NULL)
		{
			delete _bFood;
			_bFood = NULL;
		}
	}
	
	void run();
};



class PauseScene
{
private:
	//Menu _menu
};

#endif // !_SCENE_H