#include "Engine.h"
#include "Game.h"

Engine engine;
bool quit = false;
Uint64 previousTicks = SDL_GetPerformanceCounter();

void update()
{
	SDL_Event event;
	quit = false;


	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
			{
				player.input();
			}

			if (event.type == SDL_KEYUP && event.key.repeat == 0)
			{
				player.hasInput = false;
			}
		}

		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 deltaTicks = ticks - previousTicks;
		previousTicks = ticks;

		deltaTime = static_cast<float>((deltaTicks)) / static_cast<float>(SDL_GetPerformanceFrequency());

		//std::cout << "FPS: " << std::to_string(1.0f / deltaTime) << std::endl;
		//std::cout << "DeltaTime: " << deltaTime << std::endl;

		player.move();
		engine.render();
		player.render();
		SDL_RenderPresent(renderer);
	}
}

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

		update();
	}


	engine.close();
	return 0;
}