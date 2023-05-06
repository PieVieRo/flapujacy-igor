#pragma once
#include <raylib.h>

#include "Pipes.hpp"

class Igor {
public:
	Igor(Texture2D igorTexture);
	void draw();
	bool isAlive();
	void jump();
	void move(float deltaTime);
	bool collision(Pipes rura);
	void die();
private:
	Texture2D igorTexture;
	float x, y;
	bool dead;
	float momentum;
	float gravity;
	float maxDown;
};
