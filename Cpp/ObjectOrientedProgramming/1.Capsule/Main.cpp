#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "NameCard.h"
#include "Time.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Rectangle rectangle = Rectangle(3.f, 4.f);    // 가로, 세로 길이 전달.
    std::cout << "면적: " << rectangle.GetArea() << "\n";
    std::cout << "둘레: " << rectangle.GetSize() << "\n";

    Circle circle = Circle(5.f);                 // 원의 반지름 전달.
    std::cout << "면적: " << circle.GetArea() << "\n";
    std::cout << "둘레: " << circle.GetSize() << "\n";

    // NameCard(이름, 전화번호, 주소, 직급);
    NameCard jang = NameCard("Jang Se Yun", "010-1111-1111", "서울시...", "Freelancer");
    jang.ShowData();

    Time time1 = Time(10);            // 10시 0분 0초.
    Time time2 = Time(10, 20);        // 10시 20분 0초.
    Time time3 = Time(10, 20, 30);    // 10시 20분 30초.

    time2.ShowTime();
    time2.ShowTimeInSeconds();
}