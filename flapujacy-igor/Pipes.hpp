#pragma once
#include <SDL.h>
#include <SDL_image.h>

#include "Entity.hpp"

class Pipes {
public:
	Pipes(SDL_Texture* ruraTekstura, int offset);
	Entity* get_gornaRura();
	Entity* get_dolnaRura();
	void move(float delta);
	void checkCollision(Entity* igor);
	bool checkOOB();
private:
	Entity gornaRura, dolnaRura;
};
