#pragma once
#include "Actor/DrawableActor.h"

class MineIndicator : public DrawableActor
{
    RTTI_DECLARATIONS(MineIndicator, DrawableActor)
public:
    MineIndicator(const Vector2& position, int mineCount = 0);
    virtual ~MineIndicator() override;
    virtual void Update(float deltaTime) override;
    void Open();
    void OnFlag();
    bool GetOpened();
    int GetCount();
private:
    int mineCount = 0;
    char* viewImage = nullptr;
    char* coveredImage = nullptr;
    bool isOpened = false;
    bool isFlaged = false;
    char* flagImage = nullptr;
};