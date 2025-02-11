#pragma once

#include <iostream>
#include <string>
#include "Firetruck.h"
#include "INamedPerson.h"

class FirefighterBase : public INamedPerson
{
public:
    FirefighterBase(const std::string& name)
        : name(name)
    {

    }

    // 불끄기(ExtinguishFire).
    // 순수 가상함수.
    virtual void ExtinguishFire() = 0;

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
    virtual std::string GetName() const override 
    {
        return name; 
    }
    void SetName(const std::string& name)
    {
        this->name = name;
    }

protected:
    std::string name;

};