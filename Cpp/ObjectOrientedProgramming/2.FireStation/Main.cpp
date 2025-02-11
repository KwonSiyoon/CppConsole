#include "FireChief.h"
#include "TraineeFirefighter.h"
#include "FireStation.h"
#include "Administrator.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 소방서 생성.
    FireStation* fireStation = new FireStation();

    // 관리자 생성.
    Administrator* admin = new Administrator("관리자", "태준", "장");

    Firetruck* truckOne = new Firetruck();
    Firefighter* roonie = new Firefighter("로니");
    Firefighter* james = new Firefighter("제임스");
    Firefighter* bill = new TraineeFirefighter("빌");

    // 소방서장.
    FireChief* harry = new FireChief("해리", roonie);
    truckOne->SetDriver(harry);
    harry->Drive(truckOne, Point(200, 300));
    harry->ExtinguishFire();


    // 출근.
    fireStation->ClockIn(admin);
    fireStation->ClockIn(roonie);
    fireStation->ClockIn(james);
    fireStation->ClockIn(bill);
    fireStation->ClockIn(harry);
    
    // 이름 확인.
    fireStation->RollCall();



    // 다형성.
    FirefighterBase* stillHarry = harry;
    stillHarry->ExtinguishFire();
    bill->ExtinguishFire();

    // 운전자 설정.
    truckOne->SetDriver(roonie);

    // 소방차 이동.
    roonie->Drive(truckOne,Point(10, 5));


    // 운전자 설정.
    truckOne->SetDriver(james);

    // 소방차 이동.
    james->Drive(truckOne, Point(-10, -5));
    roonie->Drive(truckOne,Point(10, 5));


    // 메모리 해제
    delete truckOne;
    delete roonie;
    delete james;
    delete bill;
    delete harry;
    delete fireStation;
    delete admin;
}