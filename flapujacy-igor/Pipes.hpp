#pragma once
#include <raylib.h>
#include <iostream>
class Pipes {
public:
	Pipes(int offset, Image* ruryImage, Image* ruryImageKopia);
	void move(float deltaTime);
	void draw();
	float get_x();
	bool checkOOB();
	void unload();
private:
	float rury_x, gornaRura_y, dolnaRura_y;
	Texture2D gornaRuraTekstura, dolnaRuraTekstura;
};
