#pragma once

struct Vec3
{
	Vec3() {};
	Vec3(float x, float y, float z)
	{
		x = this->x;
		y = this->y;
		z = this->z;
	}

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	Vec3 operator*(const float& s)const;
	Vec3 operator+=(const Vec3& v)const;
};

struct Vec2
{
	Vec2() {};
	Vec2(float x, float y)
	{
		x = this->x;
		y = this->y;
	}

	float x = 0.0f;
	float y = 0.0f;

	Vec2 operator*(const float& s)const;
	Vec2 operator+=(const Vec2& v)const;
};

struct Transform
{
	Transform() {};
	Transform(Vec3 p, Vec3 r, Vec3 s)
	{
		position = p;
		rotation = r;
		scale = s;
	}

	Vec3 position;
	Vec3 rotation;
	Vec3 scale;
};

struct Gravity
{
	Gravity() {};
	Gravity(Vec3 f)
	{
		force = f;
	}

	Vec3 force;
};

struct RigidBody
{
	RigidBody() {};
	RigidBody(Vec3 v, Vec3 a)
	{
		velocity = v;
		acceleration = a;
	}
	Vec3 velocity;
	Vec3 acceleration;
};

struct Renderable
{
	Renderable() {};

	Renderable(Vec3 c)
	{
		color = c;
	}

	Vec3 color;
};