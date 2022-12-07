#include "Player.h"


void Player::move(AABB& collider)
{
	xPosition += xVelocity;
	collider.xPosition = xPosition;

	if ((xPosition < 0) || 
		(xPosition + playerRect.w > 1152) ||
		checkIntersection(playerCollider, collider) )
	{
		xPosition -= xVelocity;
		playerCollider.xPosition = xPosition;
	}

	yPosition += yVelocity;
	collider.yPosition = yPosition;

	if ((yPosition < 0) ||
		(yPosition + playerRect.h > 648) ||
		checkIntersection(playerCollider, collider))
	{
		yPosition -= xVelocity;
		playerCollider.yPosition = yPosition;
	}
}