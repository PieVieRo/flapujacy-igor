#pragma once
#include <raylib.h>

class Igor {
public:
	Igor(Texture2D igorTexture);
	void draw();
private:
	Texture2D igorTexture;
	float x, y;
	

};
