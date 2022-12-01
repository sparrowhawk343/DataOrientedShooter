//#include <SDL.h>
//#include <SDL_image.h>
//#include <stdio.h>
//#include <iostream>
//#include <vector>
//
//const int SCREEN_WIDTH = 1152;
//const int SCREEN_HEIGHT = 648;
//
//bool quit = false;
//
//bool init();
//void close();
//void input();
//bool loadMedia();
//SDL_Surface* loadSurface(std::string path);
//SDL_Texture* loadTexture(std::string path);
//
//SDL_Window* window = NULL;
//
//SDL_Surface* screenSurface = NULL;
//
//SDL_Surface* displaySurface = NULL;
//
//SDL_Renderer* renderer = NULL;
//
//SDL_Texture* backgroundTexture = NULL;
//
//SDL_Rect outlineRect = { 500, 250, 50, 50 };
//
//
//
//void input()
//{
//	SDL_Event inputEvent;
//
//	const Uint8* keystates = SDL_GetKeyboardState(NULL);
//	while (SDL_PollEvent(&inputEvent))
//	{
//		if (inputEvent.type == SDL_QUIT)
//		{
//			quit = true;
//		}
//
//		if (keystates[SDL_SCANCODE_W])
//		{
//			std::cout << "Up" << std::endl;
//		}
//
//		if (keystates[SDL_SCANCODE_S])
//		{
//			std::cout << "Down" << std::endl;
//		}
//
//		if (keystates[SDL_SCANCODE_A])
//		{
//			std::cout << "Left" << std::endl;
//		}
//
//		if (keystates[SDL_SCANCODE_D])
//		{
//			std::cout << "Right" << std::endl;
//		}
//	}
//}
//
//
//bool init()
//{
//	bool success = true;
//
//	if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	{
//		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
//		success = false;
//	}
//	else
//	{
//		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//		if (window == NULL)
//		{
//			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//			success = false;
//		}
//		else
//		{
//			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
//			if (renderer == NULL)
//			{
//				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
//				success = false;
//			}
//			else
//			{
//				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//			}
//
//			int imgFlags = IMG_INIT_PNG;
//			if (!(IMG_Init(imgFlags) & imgFlags))
//			{
//				printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
//				success = false;
//			}
//			else
//			{
//				screenSurface = SDL_GetWindowSurface(window);
//			}
//		}
//
//	}
//
//	return success;
//}
//
//SDL_Texture* loadTexture(std::string path)
//{
//	SDL_Texture* newTexture = NULL;
//
//	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
//
//	if (loadedSurface == NULL)
//	{
//		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
//	}
//	else
//	{
//		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
//		if (newTexture == NULL)
//		{
//			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
//		}
//		SDL_FreeSurface(loadedSurface);
//	}
//
//	return newTexture;
//}
//
//bool loadMedia()
//{
//	bool success = true;
//
//	backgroundTexture = loadTexture("background.png");
//	if (backgroundTexture == NULL)
//	{
//		printf("Failed to load texture image!\n");
//		success = false;
//	}
//
//
//	return success;
//}
//
//void close()
//{
//	SDL_FreeSurface(displaySurface);
//	SDL_DestroyTexture(backgroundTexture);
//	backgroundTexture = NULL;
//
//	displaySurface = NULL;
//
//	SDL_DestroyWindow(window);
//	SDL_DestroyRenderer(renderer);
//	renderer = NULL;
//	window = NULL;
//
//	IMG_Quit();
//	SDL_Quit();
//}
//
//int main(int argc, char* args[])
//{
//	if (!init())
//	{
//		printf("Failed to initialize!\n");
//	}
//	else
//	{
//		if (!loadMedia())
//		{
//			printf("Failed to load media!\n");
//		}
//		else
//		{
//			SDL_BlitSurface(displaySurface, NULL, screenSurface, NULL);
//
//			SDL_UpdateWindowSurface(window);
//		}
//
//		SDL_Event e;
//		quit = false;
//		while (!quit)
//		{
//			while (SDL_PollEvent(&e))
//			{
//				if (e.type == SDL_QUIT)
//				{
//					quit = true;
//				}
//
//				if (e.type == SDL_KEYDOWN)
//				{
//					input();
//				}
//			}
//
//
//			SDL_RenderClear(renderer);
//			SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
//			
//			SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
//			SDL_RenderDrawRect(renderer, &outlineRect);
//
//			SDL_RenderPresent(renderer);
//		}
//	}
//
//	close();
//	return 0;
//
//
//}
