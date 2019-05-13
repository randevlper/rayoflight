#include"Box2D2Ray.h"
#include "Box2D/Box2D.h"
#include "raylib.h"

Vector2 Box2D2Ray::B2DtoVector2(b2Vec2 value)
{
	return Vector2{ value.x, value.y };
}