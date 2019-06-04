#include "Body.h"
#include "Box2D/Box2D.h"
#include "Utility/Box2D2Ray.h"
#include "raylib.h"
#include <cstdio>
#include <vector>

Body::Body(b2World* world, b2BodyDef& bDef, b2PolygonShape& bShape)
{
	_body = world->CreateBody(&bDef);
	_body->CreateFixture(&bShape, 0.0f);

}

Body::Body(b2World* world, b2BodyDef& bDef, b2FixtureDef& fixtureDef)
{
	_body = world->CreateBody(&bDef);
	if (fixtureDef.shape == nullptr) {
		//Oop
		printf("Fixture def does not have a shape!");
	}
	_body->CreateFixture(&fixtureDef);
}

Body::~Body()
{
	//world is responsible for removing body
	//delete _body;
}

void Body::Init()
{
}

void Body::Render()
{
	b2Fixture* f = _body->GetFixtureList();
	b2EdgeShape* edge;
	int32 num;
	switch (f->GetType())
	{
	case b2Shape::Type::e_chain: {
		b2ChainShape* chain = (b2ChainShape*)f->GetShape();
		break;
	}
	case b2Shape::Type::e_circle: {
		b2CircleShape* circle = (b2CircleShape*)f->GetShape();
		break;
	}
	case b2Shape::Type::e_edge: {
		b2EdgeShape* edge = (b2EdgeShape*)f->GetShape();
		break;
	}
	case b2Shape::Type::e_polygon: {
		b2PolygonShape* polygon = (b2PolygonShape*)f->GetShape();
		std::vector<Vector2> lines;
		for (size_t i = 0; i < polygon->m_count; i++)
		{
			b2Vec2 wp = _body->GetWorldPoint(polygon->m_vertices[i]);
			lines.push_back( Box2D2Ray::B2DtoVector2(wp));
		}
		b2Vec2 last = _body->GetWorldPoint(polygon->m_vertices[0]);
		lines.push_back(Box2D2Ray::B2DtoVector2(last));
		DrawLineStrip(lines.data(), polygon->m_count + 1, RED);
		//DrawRectangle(GetTransform().p.x, GetTransform().p.y, 10.0f, 10.0f, RED);

		//About DrawPolyEx(), points are expected to be provided definning counter-clock-wise 
		//order triangles. flip second and third point and you will get the triangle drawn.
		break;
	}
	default:
		break;
	}
	//DrawPolyEx(
}

void Body::Tick(float delta)
{
}

const b2Transform Body::GetTransform()
{
	return _body->GetTransform();
}

void Body::SetTransform(b2Vec2& position, float& rot)
{
	_body->SetTransform(position, rot);
}
