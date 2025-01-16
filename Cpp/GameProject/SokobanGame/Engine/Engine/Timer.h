#pragma once
#include "Core.h"

class ENGINE_API Timer
{
public:
    // 생성자에서 타이머의 목표 시간 설정.
    Timer(float targetTime);
    void Update(float deltaTime);       // 타이머 업데이트.
    void Reset();                        // 타이머 초기화.
    // 타이머가 목표 시간을 경과했는지 확인.
    inline bool IsTimeOut() const { return elapsedTime >= targetTime; } 
    // 목표시간을 변경할 때 사용할 Setter.
    inline void SetTime(float targetTime) { this->targetTime = targetTime; }

private:

    float elapsedTime = 0.0f;
    float targetTime = 0.0f;
};