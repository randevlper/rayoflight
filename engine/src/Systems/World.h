#pragma once
#include "Nodes/Node.h"
#include "Box2D/Dynamics/b2World.h"

//Holds onto world information such as all of the nodes
class World
{
public:
	World();
	~World();

	void Tick(float delta);
	void Step(float timeStep, int velocityIterations, int positionIterations);
	void Render();

	void SetGravity(b2Vec2 value);
	b2Vec2 GetGravity();
	b2World* GetPhysicsWorld();

	//Add Node
	bool AddNode(Node * value);

private:

	static const int _maxNodes = 16;
	Node* _nodes[_maxNodes];
	int _nodesNum;
	b2World * _b2World;
};