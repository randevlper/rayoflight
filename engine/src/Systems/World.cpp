#include "Box2D/Box2D.h"
#include "Systems/World.h"

World::World()
{
	_nodesNum = {};
	_nodesNum = 0;
	_b2World = new b2World(b2Vec2_zero);
}

World::~World()
{
	delete _b2World;
}

void World::Tick(float delta)
{
	for (size_t i = 0; i < _nodesNum; i++)
	{
		_nodes[i].Tick(delta);
	}
}

void World::Step(float timeStep, int velocityIterations, int positionIterations)
{
	_b2World->Step(timeStep, velocityIterations, positionIterations);
}

void World::SetGravity(b2Vec2 value)
{
	_b2World->SetGravity(value);
}

b2Vec2 World::GetGravity()
{
	return _b2World->GetGravity();
}
