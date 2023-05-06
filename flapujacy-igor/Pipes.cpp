#include "Pipes.hpp"

Pipes::Pipes(int offset, Image* ruryImage, Image* ruryImageKopia)
{
	// Obrazek gornej rury
	ImageResize(ruryImage, 96, 20 + offset);
	// obrazek dolnej rury
	ImageResize(ruryImageKopia, 96, 720 - (20 + offset +180));
	this->gornaRuraTekstura = LoadTextureFromImage(*ruryImage);
	this->dolnaRuraTekstura = LoadTextureFromImage(*ruryImageKopia);
	this->rury_x = 1280;
	this->gornaRura_y = 0;
	this->dolnaRura_y = 20 + offset + 180;
	UnloadImage(*ruryImage);
	UnloadImage(*ruryImageKopia);
}

void Pipes::move(float deltaTime) {
	this->rury_x -= 100 * deltaTime;
}

void Pipes::draw() {
	DrawTexture(gornaRuraTekstura, rury_x, gornaRura_y, WHITE);
	DrawTexture(dolnaRuraTekstura, rury_x, dolnaRura_y, WHITE);
}

bool Pipes::checkOOB() {
	return this->rury_x + 96 <= 0;
}

float Pipes::get_rury_x() {
	return this->rury_x;
}

float Pipes::get_dolnaRura_y() {
	return this->dolnaRura_y;
}

void Pipes::unload() {
	UnloadTexture(gornaRuraTekstura);
	UnloadTexture(dolnaRuraTekstura);
}
