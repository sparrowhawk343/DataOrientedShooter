#pragma once
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>

extern SDL_Renderer* renderer;
extern float deltaTime;

class Engine
{
	SDL_Texture* backgroundTexture = NULL;

	SDL_Rect outlineRect = { 500, 250, 50, 50 };

public:

	bool init();
	void close();
	
	bool loadMedia();
	SDL_Texture* loadTexture(std::string path);

	void renderBackground();

	static const int SCREEN_WIDTH = 1152;
	static const int SCREEN_HEIGHT = 648;

	//SDL_Renderer* renderer = NULL;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* displaySurface = NULL;

	
};