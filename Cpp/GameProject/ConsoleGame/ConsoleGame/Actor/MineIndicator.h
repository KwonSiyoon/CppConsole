#pragma once
#include "Actor/DrawableActor.h"
#include "functional"

class MineIndicator : public DrawableActor
{
    RTTI_DECLARATIONS(MineIndicator, DrawableActor)
public:
    MineIndicator(const Vector2& position, int mineCount = 0, std::function<void()> decreaseCount = nullptr);
    virtual ~MineIndicator() override;
    virtual void Update(float deltaTime) override;
    void Open();
    void OnFlag();
    bool GetFlag();
    bool GetOpened();
    int GetCount();
private:
    int mineCount = 0;
    char* viewImage = nullptr;
    char* coveredImage = nullptr;
    bool isOpened = false;
    bool isFlaged = false;
    char* flagImage = nullptr;
    std::function<void()> decreaseCount = nullptr;
};