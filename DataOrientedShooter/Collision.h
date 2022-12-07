#pragma once
#include <SDL.h>

struct AABB
{
	static AABB initializeAABB(float x, float y, float w, float h);

	float xPosition;
	float yPosition;

	float x_min;
	float y_min;

	float x_max;
	float y_max;
};

SDL_Rect* drawBox(const AABB& box);

bool checkIntersection(const AABB& a, const AABB& b);