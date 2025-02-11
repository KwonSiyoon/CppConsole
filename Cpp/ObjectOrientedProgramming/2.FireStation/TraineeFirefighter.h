#pragma once

#include "Firefighter.h"

class TraineeFirefighter : public Firefighter
{
public:
    TraineeFirefighter(const std::string& name, bool hoseTrainedOnFire = false)
        : Firefighter(name), hoseTrainedOnFire(hoseTrainedOnFire)
    {

    }

protected:
    // 호스를 연다.
    virtual void TurnOnHose() override
    {
        if (hoseTrainedOnFire)
        {
            Firefighter::TurnOnHose();
            //std::cout << "불이 꺼지고 있습니다.\n";
        }
        else
        {
            std::cout << "물이 엉뚱한 곳으로 튀고 있습니다.\n";
        }
    }
    // 호스를 겨냥한다.
    virtual void TrainHoseOnFire() override
    {
        hoseTrainedOnFire = true;
        Firefighter::TrainHoseOnFire();
        //std::cout << "호스를 불이 발생한 곳에 겨냥하고 있습니다.\n";
    }

private:

    // 호스가 불에 정확하게 조준되는지 여부를 결정.
    bool hoseTrainedOnFire = false;

};