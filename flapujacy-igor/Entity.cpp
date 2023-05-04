#include "Entity.hpp"

Entity::Entity(float x, float y, int desired_h, int desired_w, SDL_Texture* texture, bool isIgor) : x(x), y(y), texture(texture), desired_h(desired_h), desired_w(desired_w), isIgor(isIgor), isAlive(true)
{
	this->momentum = 0;
	this->currentFrame.x = 0;
	this->currentFrame.y = 0;
	SDL_QueryTexture(texture, NULL, NULL, &this->currentFrame.w, &this->currentFrame.h);
	
	gravity = 200;
	maxDown = -500;
}

float Entity::get_x() {
	return this->x;
}

float Entity::get_y() {
	return this->y;
}

int Entity::get_desired_w()
{
	return this->desired_w;
}

int Entity::get_desired_h() {
	return this->desired_h;
}

SDL_Texture* Entity::get_texture() {
	return this->texture;
}

SDL_Rect Entity::get_currentFrame() {
	return this->currentFrame;
}

void Entity::jump() {
	momentum = 150;
}

void Entity::move(float delta) {
	if (isIgor) {
		this->y -= momentum * delta;
		if (this->y <= 0)
			momentum = 0;
		momentum -= gravity * delta;
		if (momentum < maxDown)
			momentum = maxDown;
		if (this->y > 720 - 96)
			this->y = 720 - 96;
		return;
	}
	// rura
	this->x -= 100 * delta;
}

void Entity::die() {
	this->isAlive = false;
}

void Entity::respawn() {
	this->y = 200;
}
