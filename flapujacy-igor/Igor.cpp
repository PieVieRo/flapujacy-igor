#include "Igor.hpp"

Igor::Igor(Texture2D igorTexture) : igorTexture(igorTexture), x(100), y(200)
{
}

void Igor::draw() {
	DrawTexture(igorTexture, x, y, WHITE);
}
