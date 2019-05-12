//Test integration of Box2D and Raylib
#include "Context.h"

int main(int argc, char** argv) {
	Context* context = new Context(argc, argv);

	while (!context->ShouldClose())
	{
		//Do your stuff here
		context->Tick();
	}
}