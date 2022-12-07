#include "collision.h"



AABB AABB::initializeAABB(float x, float y, float w, float h)
{
	AABB box;
	box.x_min = x - w / 2;
	box.y_min = y - h / 2;
	box.x_max = x + w / 2;
	box.y_max = y + h / 2;

	return box;
}

SDL_Rect* drawBox(const AABB& box)
{
	SDL_Rect rect = {
		box.x_min,
		box.y_min,
		box.x_max - box.x_min,
		box.y_max - box.y_min };

	return &rect;
	//SDL_RenderDrawRect(renderer, &rect);
}

bool checkIntersection(const AABB& a, const AABB& b)
{
	return (a.x_max > b.x_min &&
		b.x_max > a.x_min &&
		a.y_max > b.y_min &&
		b.y_max > a.y_min);
}