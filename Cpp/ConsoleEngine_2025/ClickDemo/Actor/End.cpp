#include "End.h"
#include "Engine/Engine.h"

End::End()
    : DrawableActor("e")
{
    color = Color::Green;
    position = Vector2(5, 5);
}

void End::Update(float deltaTime)
{
    DrawableActor::Update(deltaTime);

    

    

}
