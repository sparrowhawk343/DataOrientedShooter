#include <SDL.h>

class Player
{
public:

	SDL_Rect playerRect = { 500, 250, 50, 50 };
	static const int maxVelocity = 10;

	Player();

	void move(SDL_Rect& collider);
	void render();

private:

	int xVelocity, yVelocity;
	int xPosition, yPosition;

	SDL_Rect playerCollider;


};