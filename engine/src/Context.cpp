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

	_world = new World();
	_world->SetGravity(_gravity);
}

Context::~Context()
{
	CloseWindow();
}

void Context::Tick()
{
	_world->Tick(GetFrameTime());
	_world->Step(_timeStep, _velocityIterations, _positionIterations);
	BeginDrawing();
	//Draw Here
		ClearBackground(RAYWHITE);
		DrawText("Ayse what are you doing...", 190, 200, 20, LIGHTGRAY);
		_world->Render();
	EndDrawing();
}

bool Context::ShouldClose()
{
	return WindowShouldClose();
}

World* Context::GetWorld()
{
	return _world;
}

b2World* Context::GetPhysicsWorld()
{
	return _world->GetPhysicsWorld();
}

float Context::GetScreenWidth()
{
	return _screenWidth;
}

float Context::GetScreenHeight()
{
	return _screenHeight;
}
