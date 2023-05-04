#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Entity {
public:
	Entity(float x, float y, int desired_w, int desired_h, SDL_Texture* texture, bool isIgor);

	float get_x();
	float get_y();
	int get_desired_w();
	int get_desired_h();
	SDL_Texture* get_texture();
	SDL_Rect get_currentFrame();
	void jump();
	void move(float delta);
	
	bool isAlive;
	void die();
	void respawn();
private:
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* texture;
	int desired_w, desired_h;
	int gravity, maxDown;
	float momentum;
	bool isIgor;
};
