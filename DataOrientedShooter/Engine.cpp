#include "Engine.h"

SDL_Renderer* renderer = NULL;
float deltaTime = 0;

	bool Engine::init()
	{
		bool success = true;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			window = SDL_CreateWindow("DataDrivenShooter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (window == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
				if (renderer == NULL)
				{
					printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
					success = false;
				}
				else
				{
					SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				}

				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
				else
				{
					screenSurface = SDL_GetWindowSurface(window);
				}
			}

		}

		return success;
	}

	bool Engine::loadMedia()
	{
		bool success = true;

		backgroundTexture = loadTexture("background.png");
		if (backgroundTexture == NULL)
		{
			printf("Failed to load texture image!\n");
			success = false;
		}


		return success;
	}
	
	void Engine::close()
	{
		SDL_FreeSurface(displaySurface);
		SDL_DestroyTexture(backgroundTexture);
		backgroundTexture = NULL;

		displaySurface = NULL;

		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		renderer = NULL;
		window = NULL;

		IMG_Quit();
		SDL_Quit();
	}

	SDL_Texture* Engine::loadTexture(std::string path)
	{
		SDL_Texture* newTexture = NULL;

		SDL_Surface* loadedSurface = IMG_Load(path.c_str());

		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		else
		{
			newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			}
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}



	void Engine::renderBackground()
	{
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);

		//SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
		//SDL_RenderDrawRect(renderer, &outlineRect);

		//SDL_RenderPresent(renderer);
	}