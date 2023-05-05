#include <iostream>
#include <raylib.h>
#include <vector>
#include <random>
#include <string>

#include "Igor.hpp"
#include "Pipes.hpp"

//Screen dimension constants
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

const float ruraSpawn = 5.0f;
int wynik = 0;
int najwyzszy = 0;

int main(int argc, char* argv[]) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, u8"FLAPUJ¥CY IGOR");
	Image domImage = LoadImage("images/dom.jpg");
	ImageResize(&domImage, SCREEN_WIDTH, SCREEN_HEIGHT);
	Texture2D domTexture = LoadTextureFromImage(domImage);
	
	Image igorImage = LoadImage("images/igor.png");
	ImageResize(&igorImage, 96, 96);
	Igor igor(LoadTextureFromImage(igorImage));

	

	while (!WindowShouldClose()) {
		float deltaTime = GetFrameTime();
		/*
			KEYBOARD
		*/
		if (igor.isAlive()) {
			if (IsKeyPressed(KEY_UP)) {
				igor.jump();
			}
		} else {
			if (GetKeyPressed()) {
				
			}
		}

		/*
			PHYSICS
		*/
		igor.move(deltaTime);


		/*
		*	DRAWING
		*/
		BeginDrawing();

		ClearBackground(WHITE);
		DrawTexture(domTexture, 0, 0, WHITE);
		igor.draw();

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

