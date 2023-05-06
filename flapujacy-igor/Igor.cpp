#include "Igor.hpp"

Igor::Igor(Texture2D igorTexture) : igorTexture(igorTexture), x(100), y(200), dead(false), momentum(0), gravity(1000), maxDown(-500)
{
}

void Igor::draw() {
	DrawTexture(igorTexture, x, y, WHITE);
}

bool Igor::isAlive() {
	return !dead;
}

void Igor::jump() {
	this->momentum = 350;
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

bool Igor::collision(Pipes rura) {
	if (!(this->x + 96 > rura.get_rury_x() && this->x < rura.get_rury_x() + 96)) {
		return false;
	}

	return	!((this->y + 96 < rura.get_dolnaRura_y()) && (this->y > rura.get_dolnaRura_y() - 180));
}

void Igor::die() {
	this->dead = true;
}

void Igor::respawn() {
	this->y	       = 200;
	this->momentum = 0;
	this->dead     = false;
}
