#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height) : window(NULL), renderer(NULL) {
	this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
		std::cout << "window padl f. ERROR: " << SDL_GetError() << std::endl;

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Texture* RenderWindow::loadTexture(const char* filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == NULL)
		std::cout << "tekstura sie nei zaladowala lol. ERROR" << SDL_GetError() << std::endl;
	
	return texture;
}

void RenderWindow::cleanUp() {
	SDL_DestroyWindow(this->window);
}

void RenderWindow::clear() {
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& entity) {
	SDL_Rect src;
	src.x = entity.get_currentFrame().x;
	src.y = entity.get_currentFrame().y;
	src.w =	entity.get_currentFrame().w;
	src.h = entity.get_currentFrame().h;

	SDL_Rect dst;
	dst.x = entity.get_x();
	dst.y = entity.get_y();
	dst.w = entity.get_desired_w();
	dst.h = entity.get_desired_h();
	SDL_RenderCopy(renderer, entity.get_texture(), &src, &dst);
}

void RenderWindow::display() {
	SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderWindow::get_renderer() {
	return this->renderer;
}
