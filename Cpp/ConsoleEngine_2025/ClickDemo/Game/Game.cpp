#include "Game.h"

#include "Level/MenuLevel.h"
#include "Level/DemoLevel.h"
#include "Level/RedBlackLevel.h"
#include "Actor/Actor.h"

Game* Game::instance = nullptr;

Game::Game()
	: Engine()
{
	instance = this;
	menuLevel = new MenuLevel();
}

Game::~Game()
{
	if (showMenu)
	{
		delete backLevel;
		backLevel = nullptr;
		mainLevel = nullptr;
	}
	else
	{
		delete mainLevel;
		mainLevel = nullptr;
	}

	delete menuLevel;
	menuLevel = nullptr;
}

void Game::ToggleMenu()
{
	Clear();
	showMenu = !showMenu;
	if (showMenu)
	{
		backLevel = mainLevel;
		mainLevel = menuLevel;
	}
	else
	{
		mainLevel = backLevel;
	}
}

void Game::ClearAndLoadLevel(Level* level)
{
    if (mainLevel)
    {
        delete mainLevel;
        mainLevel = nullptr;
    }
    LoadLevel(level);
}

void Game::GoToRedBlackLevel()
{
    ToggleMenu();
    Clear();
    ClearAndLoadLevel(new RedBlackLevel());
}

void Game::GoToAStar()
{
    ToggleMenu();
    Clear();
    ClearAndLoadLevel(new DemoLevel());
}


