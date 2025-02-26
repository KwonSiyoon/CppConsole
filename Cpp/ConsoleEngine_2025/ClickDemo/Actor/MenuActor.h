#pragma once

#include "Actor/DrawableActor.h"
#include "functional"

class MenuActor : public DrawableActor
{
    RTTI_DECLARATIONS(MenuActor, DrawableActor)
public:
    MenuActor(const char* text, std::function<void()> onSelected)
        : DrawableActor(text), onSelected(onSelected)
    {
    }
    void SetColor(Color color) { this->color = color; }
public:
    std::function<void()> onSelected;
private:
};