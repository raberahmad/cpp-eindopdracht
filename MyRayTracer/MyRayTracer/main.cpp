#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <glm/glm.hpp>
#include "Sphere.h"
#include "Vlak.h"
#include <SDL.h>
#include <ppl.h>
#include "Raytracer.h"


using namespace std;
using namespace glm;

float height = 640.0f;
float width = 840.0f;

Raytracer* myTracer = new Raytracer();

vec3** image = new vec3 * [width];





bool draw(SDL_Surface* surface, int x, int y, int r, int g, int b) {

	if (y < 0 || y >= height || x < 0 || x >= width) {
		return false;
	}

	Uint32 colorSDL = SDL_MapRGB(surface->format, r, g, b);
	Uint32* bufferPointer;

	bufferPointer = (Uint32*)surface->pixels + y * surface->pitch / 4 + x;
	*bufferPointer = colorSDL;
	bufferPointer += surface->pitch / 4;

	return true;
}

void writeToScreen(SDL_Surface* surface) {
	//for every pixel loop
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; ++j) {
			float pixNormX = (i + 0.5f) / width; //normalise pixel to range 0-1 and add 0.5 so ray passes to center
			float pixNormY = (j + 0.5f) / height;
			float imageAspectRatio = width / height;
			float pixRemapX = (2 * pixNormX - 1) * imageAspectRatio;  //remap coordinates to -1 1 
			float pixRemapY = 1 - 2 * pixNormY;
			float pixCameraX = pixRemapX * tan(radians(90.0) / 2);
			float pixCameraY = pixRemapY * tan(radians(90.0) / 2);
			vec3 PcameraSpace = vec3(pixCameraX, pixCameraY, -1);
			vec3 rayOrigin = vec3(0);
			vec3 rayDirection = normalize(PcameraSpace - rayOrigin);

			vec3 pixelColour = myTracer->raytrace(rayOrigin, rayDirection, 0);
			image[i][j] = pixelColour;
			draw(surface, i, j, std::min(1.0f, image[i][j].x) * 255, std::min(1.0f, image[i][j].y) * 255, std::min(1.0f, image[i][j].z) * 255);
		}
	}
}







int main(int argc, char* args[]) {

	
	for (int i = 0; i < width; ++i) {
		image[i] = new vec3[height];
	}

	SDL_Window* window = NULL;

	SDL_Surface* screen = NULL;

	window = SDL_CreateWindow("My Ray trace", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	screen = SDL_GetWindowSurface(window);

	while (true) {

		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));

		
		writeToScreen(screen);

		SDL_UpdateWindowSurface(window);
	
	}

	SDL_DestroyWindow(window);

	SDL_Quit();


	return 0;
}

