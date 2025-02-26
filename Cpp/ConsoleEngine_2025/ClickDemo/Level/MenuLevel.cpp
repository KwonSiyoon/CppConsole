#include "MenuLevel.h"
#include "Game/Game.h"
#include "Actor/MenuActor.h"


MenuLevel::MenuLevel()
{
	menuItems.PushBack(new MenuActor("Resume", []() { Game::Get().ToggleMenu(); }));
	menuItems.PushBack(new MenuActor("AStar", []() { Game::Get().GoToAStar(); }));
	menuItems.PushBack(new MenuActor("RedBlackTree", []() { Game::Get().GoToRedBlackLevel(); }));
	menuItems.PushBack(new MenuActor("Quit", []() { Game::Get().QuitGame(); }));

    for (int i = 0; i < menuItems.Size(); ++i)
    {
        AddActor(menuItems[i]);
        menuItems[i]->SetPosition(Vector2(0, i));
    }
	length = menuItems.Size();
}

MenuLevel::~MenuLevel()
{

}

void MenuLevel::Update(float deltaTime)
{
	if (Game::Get().GetKeyDown(VK_UP))
	{
		currentIndex = (currentIndex - 1 + length) % length;
	}
	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentIndex = (currentIndex + 1) % length;
	}

	

    for (int ix = 0; ix < length; ++ix)
    {
        if (ix == currentIndex)
        {
            menuItems[ix]->SetColor(selectedColor);
        }
        else
        {
            menuItems[ix]->SetColor(unselectedColor);
        }
    }
    if (Game::Get().GetKeyDown(VK_RETURN))
    {
        menuItems[currentIndex]->onSelected();
    }

    if (Game::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ToggleMenu();
    }
}
