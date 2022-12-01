#include "Engine.h"

Engine engine;

int main(int argc, char* args[])
{
	if (!engine.init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!engine.loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			SDL_BlitSurface(engine.displaySurface, NULL, engine.screenSurface, NULL);

			SDL_UpdateWindowSurface(engine.window);
		}

		engine.update();
	}


	engine.close();
	return 0;
}