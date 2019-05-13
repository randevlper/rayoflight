#include "Node2D.h"
#include "Box2D/Common/b2Math.h"

Node2D::Node2D()
{
	_transform = new b2Transform(b2Vec2_zero,b2Rot());
}

Node2D::Node2D(b2Vec2& position, b2Rot& rot)
{
	_transform = new b2Transform(position, rot);
}

Node2D::~Node2D()
{
	delete _transform;
}

void Node2D::Init()
{
	__super::Init();

}

void Node2D::Render()
{

}

void Node2D::Tick(float delta)
{

}

const b2Transform Node2D::GetTransform()
{
	return *_transform;
}

void Node2D::SetTransform(b2Vec2& position, float& rot)
{
	_transform->Set(position, rot);
}
