#pragma once

#include "Hose.h"
#include "Point.h"
#include "Ladder.h"

// 전방선언(Forward Declaration).
// 헤더 순환 참조를 방지하기 위함. 쌍방 헤더 인클루드를 방지.
// 컴파일 속도 개선을 위함.
class FirefighterBase;
class Firetruck
{
public:
    Firetruck()
    {
        ladder = new Ladder(10.0f);
    }
    ~Firetruck()
    {
        delete ladder;
    }
    void Drive(const Point& position)
    {
        if (driver == nullptr)
        {
            return;
        }

        std::cout << position << " 위치로 소방차 이동.\n";
    }

    const Ladder* GetLadder() const { return ladder; }
    const Hose* GetHose() const { return hose; }
    void SetHose(Hose* hose) { this->hose = hose; }

    class FirefighterBase* GetDriver() const { return driver; }
    void SetDriver(class FirefighterBase* driver) { this->driver = driver; }

private:
    class FirefighterBase* driver = nullptr;
    Ladder* ladder = nullptr;
    Hose* hose = nullptr;
};