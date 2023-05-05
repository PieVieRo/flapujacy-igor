#include "Igor.hpp"

Igor::Igor(Texture2D igorTexture) : igorTexture(igorTexture), x(100), y(200), dead(false), momentum(0), gravity(200), maxDown(-500)
{
}

void Igor::draw() {
	DrawTexture(igorTexture, x, y, WHITE);
}

bool Igor::isAlive() {
	return !dead;
}

void Igor::jump() {
	this->momentum = 150;
}

void Igor::move(float deltaTime) {
	this->y -= momentum * deltaTime;
	if (this->y <= 0)
		momentum = 0;
	momentum -= gravity * deltaTime;
	if (momentum < maxDown)
		momentum = maxDown;
	if (this->y > 720 - 96)
		this->y = 720 - 96;
	return;


}
