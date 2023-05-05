#pragma once
#include <raylib.h>

class Pipes {
public:
	Pipes(int offset, Image ruryImage);
	void move(float deltaTime);
	void draw();
private:
	float rury_x, gornaRura_y, dolnaRura_y;
	Texture2D gornaRuraTekstura, dolnaRuraTekstura;
};
