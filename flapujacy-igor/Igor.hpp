#pragma once
#include <raylib.h>

class Igor {
public:
	Igor(Texture2D igorTexture);
	void draw();
	bool isAlive();
	void jump();
	void move(float deltaTime);
private:
	Texture2D igorTexture;
	float x, y;
	bool dead;
	float momentum;
	float gravity;
	float maxDown;
};
