#include "FireChief.h"

int main()
{
    Firetruck* truckOne = new Firetruck();
    Firefighter* roonie = new Firefighter("로니");
    Firefighter* james = new Firefighter("제임스");

    // 소방서장.
    FireChief* harry = new FireChief("해리", roonie);
    truckOne->SetDriver(harry);
    harry->Drive(truckOne, Point(200, 300));
    harry->ExtinguishFire();

    // 다형성.
    Firefighter* stillHarry = harry;
    stillHarry->ExtinguishFire();

    // 운전자 설정.
    truckOne->SetDriver(roonie);

    // 소방차 이동.
    roonie->Drive(truckOne,Point(10, 5));


    // 운전자 설정.
    truckOne->SetDriver(james);

    // 소방차 이동.
    james->Drive(truckOne, Point(-10, -5));
    roonie->Drive(truckOne,Point(10, 5));

}