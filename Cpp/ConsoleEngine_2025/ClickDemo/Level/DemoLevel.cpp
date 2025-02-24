#include "DemoLevel.h"

#include "Actor/Start.h"
#include "Actor/End.h"
#include "Actor/Road.h"

#include "Engine/Engine.h"
#include "Algorithm/AStar.h"
#include "Algorithm/Node.h"

DemoLevel::DemoLevel()
{
    startActor = new Start();
    endActor = new End();
    startActor->SetPosition(Vector2(20, 2));
    endActor->SetPosition(Vector2(4, 4));
	AddActor(startActor);
	AddActor(endActor);
}

void DemoLevel::Update(float deltaTime)
{
    Level::Update(deltaTime);
    if (Engine::Get().GetKeyDown(VK_ESCAPE))
    {
        Engine::Get().QuitGame();
    }
    if (Engine::Get().GetKeyDown(VK_SPACE))
    {
        MakeAStarRoad();
    }
    if (Engine::Get().GetKeyDown(VK_RBUTTON))
    {
        endActor->SetPosition(Engine::Get().MousePosition());
    }
    if (Engine::Get().GetKeyDown(VK_LBUTTON))
    {
        startActor->SetPosition(Engine::Get().MousePosition());
    }
    
}

void DemoLevel::MakeAStarRoad()
{
    AStar aStar;
    std::vector<Node*> roadNodes = aStar.FindPath(startActor, endActor);
    ResetRoad();
    for (int i = 1; i < (int)roadNodes.size()-1; ++i)
    {
        Road* road = new Road(roadNodes[i]->Position());
        AddActor(road);
        roadList.emplace_back(road);
    }
}

void DemoLevel::ResetRoad()
{
    
    if (!roadList.empty())
    {
        for (auto actor : roadList)
        {
            actor->Destroy();
        }
        roadList.clear();
    }
}
