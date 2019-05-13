#include "Box2D/Box2D.h"
#include "Systems/World.h"
#include <cstdio>

World::World()
{	
	_nodesNum = 0;
	_b2World = new b2World(b2Vec2_zero);

	for (size_t i = 0; i < _maxNodes; i++)
	{
		_nodes[i] = nullptr;
	}
}

World::~World()
{
	delete _b2World;
}

void World::Tick(float delta)
{
	for (size_t i = 0; i < _nodesNum; i++)
	{
		_nodes[i]->Tick(delta);
	}
}

void World::Step(float timeStep, int velocityIterations, int positionIterations)
{

	_b2World->Step(timeStep, velocityIterations, positionIterations);
}

void World::Render()
{
	for (size_t i = 0; i < _nodesNum; i++)
	{
		_nodes[i]->Render();
	}
}

void World::SetGravity(b2Vec2 value)
{
	_b2World->SetGravity(value);
}

b2Vec2 World::GetGravity()
{
	return _b2World->GetGravity();
}

b2World* World::GetPhysicsWorld()
{
	return _b2World;
}

bool World::AddNode(Node* value)
{
	for (size_t i = 0; i < _maxNodes; i++)
	{
		if (_nodes[i] == nullptr) {
			printf("Added node\n");
			_nodes[i] = value;
			_nodesNum++;
			return true;
		}
	}
	return false;
}
