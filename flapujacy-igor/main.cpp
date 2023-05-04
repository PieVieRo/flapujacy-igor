#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <vector>
#include <random>
#include <string>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Pipes.hpp"

//Screen dimension constants
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

const float ruraSpawn = 5.0f;
int wynik = 0;

int main(int argc, char* argv[]) {
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_VIDEO) > 0) 
		std::cout << "SDL_Init padlo!!! Error: " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_JPG))
		std::cout << "IMG_Init (JPG) padlo!!! Error: " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_Init (PNG) padlo!!! Error: " << SDL_GetError() << std::endl;

	if (!(TTF_Init()))
		std::cout << "TTF_Init padlo!!! Error: " << TTF_GetError() << std::endl;

	RenderWindow window(u8"FLAPUJ¥CY IGOR", SCREEN_WIDTH, SCREEN_HEIGHT);
	
	TTF_Font*    czcionka     = TTF_OpenFont("./czcionka.ttf", 24);
	SDL_Surface* wynikSurface = TTF_RenderText_Solid(czcionka, std::to_string(wynik).c_str(), {0, 0, 0,});
	SDL_Texture* wynikTexture = SDL_CreateTextureFromSurface(window.get_renderer(), wynikSurface);
	SDL_Rect     wynikDST = { 200 - 96, 0, 70, 70 };

	SDL_Texture* domTexture  = window.loadTexture("images/dom.jpg");
	SDL_Texture* igorTexture = window.loadTexture("images/igor.png");
	SDL_Texture* ruraTexture = window.loadTexture("images/kajdanki.jpg");
	// Entity entities[] = { Entity(100, 200, 128, 128, igorTexture), Entity(10, 20, 128, 128, igorTexture), Entity(200, 300, 128, 128, igorTexture) };

	Entity igor(100, 200, 96, 96, igorTexture, true);
	std::vector<Pipes> rury = { };
	

	float timerDoRury = ruraSpawn;
	bool gameRunning = true;
	SDL_Event event;
	Uint64 prevTime = SDL_GetTicks64();
	while (gameRunning) {
		/*
			Delta time calculation
		*/
		Uint64 currTime = SDL_GetTicks64();
		double deltaTime = (currTime - prevTime) * 0.001f;
		/*
			EVENTS
		*/
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) 
				if (igor.isAlive){
					if (event.key.keysym.sym == SDLK_UP) 
						if (!event.key.repeat)
							igor.jump();
			}
				else {
					igor.isAlive = true;
					igor.respawn();
					wynik = 0;
					wynikSurface = TTF_RenderText_Solid(czcionka, std::to_string(wynik).c_str(), {0, 0, 0,});
					wynikTexture = SDL_CreateTextureFromSurface(window.get_renderer(), wynikSurface);
					rury = {};
					timerDoRury = ruraSpawn;
				}
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
		
		/*
			PHYSICS
		*/
		igor.move(deltaTime);
		if (igor.isAlive) {
			for (int i = 0; i < rury.size(); i++) {
				rury[i].move(deltaTime);
				rury[i].checkCollision(&igor);
				if (rury[i].checkOOB()) {
					rury.erase(rury.begin());
					wynik++;
					wynikSurface = TTF_RenderText_Solid(czcionka, std::to_string(wynik).c_str(), {0, 0, 0,});
					wynikTexture = SDL_CreateTextureFromSurface(window.get_renderer(), wynikSurface);
				}
			}
			timerDoRury -= deltaTime;
			if (timerDoRury <= 0) {
				timerDoRury = ruraSpawn;
				rury.push_back(Pipes(ruraTexture, rand() % 500));
			}

		}
		/*
			RENDERING
		*/
		window.clear();
		// render the background
		SDL_RenderCopy(window.get_renderer(), domTexture, NULL, NULL);
		for (Pipes rura : rury) {
			Entity* dolnaRura = rura.get_dolnaRura();
			Entity* gornaRura = rura.get_gornaRura();
			window.render(*gornaRura);
			window.render(*dolnaRura);
		}
		window.render(igor);
		SDL_RenderCopy(window.get_renderer(), wynikTexture, NULL, &wynikDST);
		// std::cout << deltaTime << std::endl;
		window.display();
		prevTime = currTime;
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}
