#pragma once
#include "Actor.h"

class ENGINE_API DrawableActor : public Actor
{
	// RTTI.
	RTTI_DECLARATIONS(DrawableActor, Actor)
public:
    DrawableActor(const char* image = "");
    virtual ~DrawableActor();

	virtual void Draw() override;
	virtual void SetPosition(const Vector2& newPosition) override;

    // 충돌 확인 함수.
    bool Intersect(const DrawableActor& other);

    inline int Width() const { return width; }

protected:
	
	char* image;                    // 화면에 그릴 문자 값.
    int width = 0;                  // 너비(문자열 길이)
    Color color = Color::White;     // 색상 값.

};