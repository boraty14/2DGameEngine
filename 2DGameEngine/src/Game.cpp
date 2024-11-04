#include "Game.h"
#include <iostream>

Game::Game()
{
	std::cout << "Constructor" << std::endl;
}

Game::~Game()
{
	std::cout << "Destructor" << std::endl;
}

void Game::Initialize()
{
	
}

void Game::Run()
{
	while (true)
	{
		ProcessInput();
		Update();
		Render();
	}
}

void Game::ProcessInput()
{

}

void Game::Update()
{
	
}

void Game::Render()
{

}

void Game::Destroy()
{

}

