#include <iostream>
#include <raylib.h>
#include <vector>
#include <random>
#include <string>

#include "Igor.hpp"
#include "Pipes.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

const float ruraSpawn = 50.0f;
int wynik = 0;
int najwyzszy = 0;

int main(int argc, char* argv[]) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, u8"FLAPUJ¥CY IGOR");
	SetTargetFPS(60);

	Image domImage = LoadImage("images/dom.jpg");
	ImageResize(&domImage, SCREEN_WIDTH, SCREEN_HEIGHT);
	Texture2D domTexture = LoadTextureFromImage(domImage);
	UnloadImage(domImage);

	Image igorImage = LoadImage("images/igor.png");
	ImageResize(&igorImage, 96, 96);
	SetWindowIcon(igorImage);
	Igor igor(LoadTextureFromImage(igorImage));
	UnloadImage(igorImage);

	std::vector<Pipes> rury = { };

	float czasDoRury = 2;

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();
		/*
			KEYBOARD
		*/
		if (igor.isAlive()) {
			if (IsKeyPressed(KEY_UP)) {
				igor.jump();
			}
		}
		else {
			if (GetKeyPressed()) {

			}
		}

		/*
			PHYSICS
		*/
		igor.move(deltaTime);
		czasDoRury -= deltaTime;
		if (czasDoRury <= 0) {
			Image ruryImage = LoadImage("images/kajdanki.jpg");
			Image ruryImageKopia = LoadImage("images/kajdanki.jpg");
			rury.push_back(Pipes(180, &ruryImage, &ruryImageKopia));
			czasDoRury = ruraSpawn;
		}
		for (int i = 0; i < rury.size(); i++) {
			rury[i].move(deltaTime);
			if (igor.collision(rury[i]))
				igor.die();
			if (rury[i].checkOOB()) {
				rury[i].unload();
				rury.erase(rury.begin());
			} 
		}
		/*
		*	DRAWING
		*/
		BeginDrawing();

		DrawTexture(domTexture, 0, 0, WHITE);
		for (int i = 0; i < rury.size(); i++) {
			rury[i].draw();
		}
		igor.draw();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

