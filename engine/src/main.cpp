//Test integration of Box2D and Raylib
#include "Context.h"
#include "Nodes/Body.h"
#include "Box2D/Box2D.h"
#include "raylib.h"

int main(int argc, char** argv) {
	Context* context = new Context(argc, argv);
	context->GetPhysicsWorld()->SetGravity(b2Vec2(0.0f, -9.81f));
	//Create ground
	//Create box

	b2BodyDef bodyDef;
	b2PolygonShape polyShape;
	b2FixtureDef fixtureDef;

	bodyDef.position.Set(context->GetScreenWidth() / 2, 0);
	polyShape.SetAsBox(100.0f, 100.0f);
	fixtureDef.shape = &polyShape;
	Body * ground = new Body(context->GetPhysicsWorld(), bodyDef, fixtureDef);

	bodyDef.position.Set(0, context->GetScreenHeight());
	polyShape.SetAsBox(50.0f, 50.0f);
	Body* test1 = new Body(context->GetPhysicsWorld(), bodyDef, fixtureDef);

	bodyDef.position.Set(context->GetScreenWidth(), 0);
	polyShape.SetAsBox(5.0f, 50.0f);
	Body* test2 = new Body(context->GetPhysicsWorld(), bodyDef, fixtureDef);


	b2Vec2 ballStartPos = { context->GetScreenWidth() / 2, 200.0f };
	float ballStartRot = 0;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(ballStartPos.x, ballStartPos.y);
	bodyDef.allowSleep = false;
	polyShape.SetAsBox(20.0f, 20.0f);
	fixtureDef.shape = &polyShape;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;
	Body * ball = new Body(context->GetPhysicsWorld(), bodyDef, fixtureDef);


	context->GetWorld()->AddNode(ground);
	context->GetWorld()->AddNode(ball);
	context->GetWorld()->AddNode(test1);
	context->GetWorld()->AddNode(test2);


	while (!context->ShouldClose())
	{
		if (IsKeyPressed(KEY_SPACE)) {
			ball->SetTransform(ballStartPos, ballStartRot);
		}

		//Do your stuff here
		context->Tick();
	}

	delete context;
}