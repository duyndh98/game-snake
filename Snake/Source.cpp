#include "Noname.h"
#include "Map.h"
#include "Snake.h"
#include "File.h"
#include "Scene.h"

int main()
{
	//resizeConsole(80, 25);
	system("color 07");
	
	// tile
	print({ 1, 25 }, "HUNTING SNAKE v1.1.0 by NDHD", C_LIGHT_AQUA, C_BLACK);

	hideCursor();

	srand((unsigned int)time(NULL));
	
	PlayScene *scene;
	do
	{
		scene = new PlayScene("map2");
		scene->run();
		if (scene != NULL)
		{
			delete scene;
			scene = NULL;
		}

	} while (false);
		
		
	return 0;
}