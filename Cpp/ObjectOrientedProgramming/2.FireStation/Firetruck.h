#pragma once

#include "Hose.h"
#include "Point.h"
#include "Ladder.h"

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

    class Firefighter* GetDriver() const { return driver; }
    void SetDriver(class Firefighter* driver) { this->driver = driver; }

private:
    class Firefighter* driver = nullptr;
    Ladder* ladder = nullptr;
    Hose* hose = nullptr;
};