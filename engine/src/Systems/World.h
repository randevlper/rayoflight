#pragma once
#include "Nodes/Node.h"
#include "Box2D/Dynamics/b2World.h"

//Holds onto world information such as all of the nodes
class World
{
public:
	World();
	World(Node * nodes[], b2Vec2& gravity);
	~World();

	void Tick(float delta);
	void Step(float timeStep, int velocityIterations, int positionIterations);

	void SetGravity(b2Vec2 value);
	b2Vec2 GetGravity();

private:

	Node _nodes[16];
	int _nodesNum;
	b2World * _b2World;
};