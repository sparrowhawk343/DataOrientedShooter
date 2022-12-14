#include "Component.h"

Vec3 Vec3::operator*(const float& s)const
{
	Vec3 vectorToReturn;
	vectorToReturn.x = x * s;
	vectorToReturn.y = y * s;
	vectorToReturn.z = z * s;

	return vectorToReturn;
}

Vec3 Vec3::operator+=(const Vec3& v)const
{
	Vec3 vectorToReturn;
	vectorToReturn.x = x + v.x;
	vectorToReturn.y = y + v.y;
	vectorToReturn.z = z + v.z;

	return vectorToReturn;
}

Vec2 Vec2::operator*(const float& s)const
{
	Vec2 vectorToReturn;
	vectorToReturn.x = x * s;
	vectorToReturn.y = y * s;

	return vectorToReturn;
}

Vec2 Vec2::operator+=(const Vec2& v)const
{
	Vec2 vectorToReturn;
	vectorToReturn.x = x + v.x;
	vectorToReturn.y = y + v.y;

	return vectorToReturn;
}