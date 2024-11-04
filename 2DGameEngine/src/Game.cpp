#include "Game.h"
#include <iostream>
#include <SDL.h>

Game::Game()
{
	isRunning = false;
	std::cout << "Constructor" << '\n';
}

Game::~Game()
{
	std::cout << "Destructor" << '\n';
}

void Game::Initialize()
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Error initializing SDL" << '\n';
		return;
	}

	SDL_ShowCursor(SDL_DISABLE);
	SDL_DisplayMode displayMode;
	SDL_GetDisplayMode(0,0, &displayMode);

	windowWidth = displayMode.w;
	windowHeight = displayMode.h;

	window = SDL_CreateWindow(
		nullptr, 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		windowWidth,
		windowHeight,
		SDL_WINDOW_BORDERLESS
	);

	if(!window)
	{
		std::cerr << "Error creating SDL window" << '\n';
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		std::cerr << "Error creating SDL renderer" << '\n';
		return;
	}

	isRunning = true;
	
}

void Game::Run()
{
	while (isRunning)
	{
		ProcessInput();
		Update();
		Render();
	}
}

void Game::ProcessInput()
{
	SDL_Event sdlEvent;
	while(SDL_PollEvent(&sdlEvent))
	{
		switch (sdlEvent.type)
		{
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_KEYDOWN:
				if(sdlEvent.key.keysym.sym == SDLK_ESCAPE)
				{
					isRunning = false;
				}
				break;
			default:
				break;
		}
	}
}

void Game::Update()
{
	
}

void Game::Render()
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void Game::Destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

