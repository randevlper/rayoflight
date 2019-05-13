#pragma once
#include "Node2D.h"

struct b2BodyDef;
class b2Body;
struct b2PolygonShape;
struct b2FixtureDef;
class b2World;

class Body : public Node2D
{
public:
	//Creates a static shape
	Body(b2World* world, b2BodyDef& bDef, b2PolygonShape& bShape);
	//Used to create a dynamic shape
	Body(b2World* world, b2BodyDef& bDef, b2FixtureDef& fixtureDef);
	~Body();
	
	void Init() override;
	void Render() override;
	void Tick(float delta) override;
	const b2Transform GetTransform() override;
	void SetTransform(b2Vec2& position, float& rot) override;

	
private:
	b2Body* _body;
};