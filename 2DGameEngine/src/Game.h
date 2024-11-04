#pragma once
#include <SDL_render.h>
#include <SDL_video.h>

class Game
{
public:
	Game();
	~Game();
	void Initialize();
	void Run();
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();

	int windowWidth;
	int windowHeight;
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
};
