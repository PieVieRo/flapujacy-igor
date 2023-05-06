#pragma once
#include <raylib.h>
#include <iostream>
class Pipes {
public:
	Pipes(int offset, Image* ruryImage, Image* ruryImageKopia);
	void move(float deltaTime);
	void draw();
	bool checkOOB();
	void unload();
	float get_rury_x();
	float get_dolnaRura_y();
private:
	float rury_x, gornaRura_y, dolnaRura_y;
	Texture2D gornaRuraTekstura, dolnaRuraTekstura;
};
