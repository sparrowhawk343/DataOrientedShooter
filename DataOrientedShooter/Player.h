#pragma once
#include <SDL.h>
#include "Collision.h"

class Player
{
public:

	SDL_Rect playerRect = { 500, 250, 50, 50 };
	static const int maxVelocity = 100;
	bool hasInput = false;

	//Player()
	//{
	//	/*playerCollider = playerCollider.initializeAABB(500, 250, 50, 50);
	//	xVelocity = 0;
	//	yVelocity = 0;
	//	xPosition = 500;
	//	yPosition = 250;*/
	//};

	void move();
	void input();
	void render();

private:

	float xVelocity = 0;
	float yVelocity = 0;
	float xPosition = 500;
	float yPosition = 250;

	

	AABB playerCollider;
};