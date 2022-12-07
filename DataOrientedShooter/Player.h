#pragma once
#include <SDL.h>
#include "Collision.h"

class Player
{
public:

	SDL_Rect playerRect = { 500, 250, 50, 50 };
	static const int maxVelocity = 10;

	Player()
	{
		playerCollider = playerCollider.initializeAABB(500, 250, 50, 50);
		xVelocity = 0;
		yVelocity = 0;
		xPosition = 0;
		yPosition = 0;
	};

	void move(AABB& collider);

private:

	int xVelocity, yVelocity;
	int xPosition, yPosition;

	AABB playerCollider;


};