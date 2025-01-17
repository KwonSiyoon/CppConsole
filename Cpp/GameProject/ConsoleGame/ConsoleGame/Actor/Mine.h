#pragma once
#include "Actor/DrawableActor.h"

class Mine : public DrawableActor
{
    RTTI_DECLARATIONS(Mine, DrawableActor)
public:
    Mine(const Vector2& position);
    virtual ~Mine() override;
    virtual void Update(float deltaTime) override;
    void Open();
    void OnFlag();
private:
    char* viewImage = nullptr;
    char* coveredImage = nullptr;
    bool isOpened = false;
    bool isFlaged = false;
    char* flagImage = nullptr;
};