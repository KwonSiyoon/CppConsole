#pragma once
#include "Actor/DrawableActor.h"
#include "functional"

class Mine : public DrawableActor
{
    RTTI_DECLARATIONS(Mine, DrawableActor)
public:
    Mine(const Vector2& position, std::function<void()> callback = nullptr);
    virtual ~Mine() override;
    virtual void Update(float deltaTime) override;
    void Open();
    void OnFlag();
    bool GetFlag();
    bool GetOpen();
private:
    char* viewImage = nullptr;
    char* coveredImage = nullptr;
    bool isOpened = false;
    bool isFlaged = false;
    char* flagImage = nullptr;
    std::function<void()> decreaseCount = nullptr;
};