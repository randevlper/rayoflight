#include "Context.h"
#include "Box2D/Box2D.h"
#include "raylib.h"

Context::Context(int argc, char** argv)
{
	InitWindow(_screenWidth, _screenHeight, _screenName);
	SetTargetFPS(_targetFPS);

	//Setup Physics
	B2_NOT_USED(argc);
	B2_NOT_USED(argv);

	_world = World();
	_world.SetGravity(_gravity);
}

Context::~Context()
{
}

void Context::Tick()
{
	_world.Tick(GetFrameTime());
	_world.Step(_timeStep, _velocityIterations, _positionIterations);
}

bool Context::ShouldClose()
{
	return WindowShouldClose();
}
