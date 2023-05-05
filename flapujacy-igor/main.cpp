#include <iostream>
#include <raylib.h>
#include <vector>
#include <random>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH  = 1280;
const int SCREEN_HEIGHT = 720;

const float ruraSpawn = 5.0f;
int wynik = 0;
int najwyzszy = 0;

int main(int argc, char* argv[]) {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, u8"FLAPUJ¥CY IGOR");
	Image dom = LoadImage("images/dom.jpg");
	ImageResize(&dom, SCREEN_WIDTH, SCREEN_HEIGHT);
	Texture2D domTexture = LoadTextureFromImage(dom);
	
	while (!WindowShouldClose()) {
		BeginDrawing();

		ClearBackground(WHITE);
		DrawTexture(domTexture, 0, 0, WHITE);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}

