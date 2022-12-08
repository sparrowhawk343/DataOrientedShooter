#include "Player.h"
#include "Engine.h"



void Player::move()
{
	if (hasInput)
	{
		xPosition += xVelocity * deltaTime;
		playerRect.x = xPosition;
		playerCollider.xPosition = xPosition;

		if (xPosition < 0 || xPosition + playerRect.w > 1152)
		{
			xPosition -= xVelocity * deltaTime;
			playerRect.x = xPosition;
			playerCollider.xPosition = xPosition;
		}

		yPosition += yVelocity * deltaTime;
		playerRect.y = yPosition;
		playerCollider.yPosition = yPosition;

		if (yPosition < 0 || yPosition + playerRect.h > 648)
		{
			yPosition -= yVelocity * deltaTime;
			playerRect.y = yPosition;
			playerCollider.yPosition = yPosition;
		}
	}
	else
	{
		xVelocity = 0.f;
		yVelocity = 0.f;
	}
}


void Player::input()
{
	SDL_Event inputEvent;

	const Uint8* keystates = SDL_GetKeyboardState(NULL);
	while (SDL_PollEvent(&inputEvent))
	{
		hasInput = true;
		if (keystates[SDL_SCANCODE_W])
		{
			yVelocity = 0.f;
			yVelocity -= maxVelocity;
			std::cout << "W" << std::endl;
		}

		if (keystates[SDL_SCANCODE_S])
		{
			yVelocity = 0.f;
			yVelocity += maxVelocity;
			std::cout << "S" << std::endl;
		}

		if (keystates[SDL_SCANCODE_A])
		{
			xVelocity = 0.f;
			xVelocity -= maxVelocity;
			std::cout << "A" << std::endl;
		}

		if (keystates[SDL_SCANCODE_D])
		{
			xVelocity = 0.f;
			xVelocity += maxVelocity;
			std::cout << "D" << std::endl;
		}
	}
}

void Player::render()
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &playerRect);
	SDL_RenderPresent(renderer);
}
