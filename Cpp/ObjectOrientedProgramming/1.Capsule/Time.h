#pragma once
#include <iostream>
class Time
{
public:
    Time() {}
    ~Time() {}
    Time(int hour)
        : hour(hour)
    {

    }
    Time(int hour, int minute)
        : hour(hour), minute(minute)
    {

    }
    Time(int hour, int minute, int second)
        : hour(hour), minute(minute), second(second)
    {

    }
    void ShowTime()
    {
        std::cout << "[" << hour << "시 " << minute << "분 " << second << "초]\n";
    }
    void ShowTimeInSeconds()
    {
        std::cout << hour * 3600 + minute * 60 + second << "초\n";
    }
private:
    int hour = 0;
    int minute = 0;
    int second = 0;

};

