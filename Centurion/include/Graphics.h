#pragma once
#include <SDL.h>
#include "Centurion.h"
#include "Image.h"
#include "Window.h"

class centurion::Graphics {

private:
	friend class centurion::Window;

	SDL_Renderer* renderer = nullptr;

	Graphics(SDL_Renderer* renderer);

public:
	~Graphics();

	void update();

	void render(centurion::Image& img, int x, int y);
	
	void render(centurion::Image& img, int x, int y, int w, int h);
};