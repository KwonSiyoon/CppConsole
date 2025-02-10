#pragma once

#include <iostream>
#include <string>
#include "Firetruck.h"

class Firefighter
{
public:
    Firefighter(const std::string& name)
        : name(name)
    {

    }
    virtual ~Firefighter() = default;
    /*virtual ~Firefighter()
    {

    }*/


    // 불끄기(ExtinguishFire).
    virtual void ExtinguishFire()
    {
        std::cout << name << " 소방관이 불을 끄고 있음.\n";
    }

    // 운전(Drive).
    void Drive(class Firetruck* truckToDrive, const class Point& position)
    {
        if (truckToDrive->GetDriver() != this)
        {
            std::cout << name << "은 운전자가 아님.\n";
            return;
        }
        truckToDrive->Drive(position);
    }

    // Getter/Setter
    const std::string GetName() const { return name; }
    void SetName(const std::string& name)
    {
        this->name = name;
    }


private:
    std::string name;

};