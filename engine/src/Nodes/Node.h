#pragma once
class Node
{
public:
	Node();
	~Node();

	void virtual Init();
	void virtual Tick(float delta);
	void virtual Render();
};

