#pragma once
#include "Node.h"

struct b2Transform;
struct b2Vec2;
struct b2Rot;

class Node2D : public Node
{
public:
	Node2D();
	Node2D(b2Vec2& position, b2Rot& rot);
	~Node2D();

	
	void Init() override;
	void Render() override;
	void Tick(float delta) override;
	virtual const b2Transform GetTransform();
	virtual void SetTransform(b2Vec2& position, float& rot);

private:
	b2Transform* _transform;
};