#include "DemoLevel.h"

#include "Actor/Start.h"
#include "Actor/End.h"
#include "Actor/Road.h"
#include "Actor/Player.h"

#include "Engine/Timer.h"
//#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Algorithm/AStar.h"
#include "Algorithm/Node.h"

DemoLevel::DemoLevel()
{
    startActor = new Start();
    endActor = new End();
    startActor->SetPosition(Vector2(20, 2));
    endActor->SetPosition(Vector2(4, 4));
    timer = new Timer(0.2f);
	AddActor(startActor);
	AddActor(endActor);
}

DemoLevel::~DemoLevel()
{
    SafeDelete(timer);
}

void DemoLevel::Update(float deltaTime)
{
    Level::Update(deltaTime);
    timer->Update(deltaTime);
    
    if (Game::Get().GetKeyDown(VK_SPACE))
    {
        MakeAStarRoad();
    }
    if (Game::Get().GetKeyDown(VK_RBUTTON))
    {
        ResetRoad();
        endActor->SetPosition(Game::Get().MousePosition());
    }
    if (Game::Get().GetKeyDown(VK_LBUTTON))
    {
        ResetRoad();
        startActor->SetPosition(Game::Get().MousePosition());
    }
    if (Game::Get().GetKeyDown(VK_TAB))
    {
        if (actorsInRoad.empty()) return;
        if (player)
        {
            player->Destroy();
            player = nullptr;
        }
        player = new Player();
        player->SetPosition(startActor->Position());
        AddActor(player);
        idx = 0;
        playMove = true;
    }
    if (playMove && player)
    {
        MovePlayerAlongRoad();
    }
    if (Game::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ToggleMenu();
    }
    
}

void DemoLevel::MakeAStarRoad()
{
    ResetRoad();
    AStar aStar;
    std::vector<class Node*> roadNodes = aStar.FindPath(startActor, endActor);
    actorsInRoad.emplace_back(startActor);
    for (int i = 1; i < (int)roadNodes.size()-1; ++i)
    {
        Road* road = new Road(roadNodes[i]->Position());
        AddActor(road);
        roadList.emplace_back(road);
        actorsInRoad.emplace_back(road);
    }
    actorsInRoad.emplace_back(endActor);

}

void DemoLevel::ResetRoad()
{
    idx = 0;
    playMove = false;
    if (player)
    {
        player->Destroy();
        player = nullptr;
    }
    if (!roadList.empty())
    {
        for (auto actor : roadList)
        {
            actor->Destroy();
        }
        roadList.clear();
    }
    if (!actorsInRoad.empty())
    {
        actorsInRoad.clear();
    }
}

void DemoLevel::MovePlayerAlongRoad()
{
    if (!player) return;
    if (timer->IsTimeOut())
    {
        if (idx < (int)actorsInRoad.size())
        {
            player->SetPosition(actorsInRoad[idx]->Position());
            ++idx;
        }
        else
        {
            playMove = false;
        }
        timer->Reset();
    }
}
