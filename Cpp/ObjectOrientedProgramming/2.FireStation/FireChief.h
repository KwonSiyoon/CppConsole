#pragma once
#include "FirefighterBase.h"

class FireChief : public FirefighterBase
{
public:
    FireChief(const std::string& name, FirefighterBase* numberOne = nullptr)
        : FirefighterBase(name), numberOne(numberOne)
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
    const FirefighterBase* GetNumberOne() const { return numberOne; }
    void SetNumberOne(FirefighterBase* numberOne) { this->numberOne = numberOne; }

private:
    void TellFirefighterToExtinguishFire(FirefighterBase* colleague)
    {
        colleague->ExtinguishFire();
    }



private:
    FirefighterBase* numberOne = nullptr;

};