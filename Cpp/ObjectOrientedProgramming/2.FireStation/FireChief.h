#pragma once
#include "Firefighter.h"

class FireChief : public Firefighter
{
public:
    FireChief(const std::string& name, Firefighter* numberOne = nullptr)
        : Firefighter(name), numberOne(numberOne)
    {

    }
    virtual void ExtinguishFire() override
    {
        if (numberOne == nullptr)
        {
            std::cout << "호출 할 소방관이 없습니다.\n";
            return;
        }
        TellFirefighterToExtinguishFire(numberOne);
    }
    

    // Getter/Setter
    const Firefighter* GetNumberOne() const { return numberOne; }
    void SetNumberOne(Firefighter* numberOne) { this->numberOne = numberOne; }

private:
    void TellFirefighterToExtinguishFire(Firefighter* colleague)
    {
        colleague->ExtinguishFire();
    }



private:
    Firefighter* numberOne = nullptr;

};