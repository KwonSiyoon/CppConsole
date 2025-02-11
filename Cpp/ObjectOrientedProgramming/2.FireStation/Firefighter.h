#pragma once

#include "FirefighterBase.h"

class Firefighter : public FirefighterBase
{
public:
    Firefighter(const std::string& name)
        : FirefighterBase(name)
    {

    }
    virtual ~Firefighter() = default;
    /*virtual ~Firefighter()
    {

    }*/


    // 불끄기(ExtinguishFire).
    virtual void ExtinguishFire() override
    {
        std::cout << name << " 소방관이 불을 끄고 있음.\n";
        TrainHoseOnFire();
        TurnOnHose();
    }

    //// 운전(Drive).
    //void Drive(class Firetruck* truckToDrive, const class Point& position)
    //{
    //    if (truckToDrive->GetDriver() != this)
    //    {
    //        std::cout << name << "은 운전자가 아님.\n";
    //        return;
    //    }
    //    truckToDrive->Drive(position);
    //}

    //// Getter/Setter
    //const std::string GetName() const { return name; }
    //void SetName(const std::string& name)
    //{
    //    this->name = name;
    //}

protected:
    // 호스를 연다.
    virtual void TurnOnHose()
    {
        std::cout << "불이 꺼지고 있습니다.\n";
    }
    // 호스를 겨냥한다.
    virtual void TrainHoseOnFire()
    {
        std::cout << "호스를 불이 발생한 곳에 겨냥하고 있습니다.\n";

    }

//private:
//    std::string name;

};