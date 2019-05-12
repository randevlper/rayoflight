#pragma once
#include "Box2D/Common/b2Math.h"
#include "Systems/World.h"

class Context
{
public:
	Context(int argc, char** argv);
	
	~Context();

	void Tick();

	bool ShouldClose();

private:
	Context();

	int _screenWidth = 800;
	int _screenHeight = 450;
	int _targetFPS = 60;
	b2Vec2 _gravity = { 0.0f, -9.81f };
	char _screenName[16] = "rayoflight";

	float32 _timeStep = 1.0f / 60.0f;
	int32 _velocityIterations = 6;
	int32 _positionIterations = 2;
	World _world;
};