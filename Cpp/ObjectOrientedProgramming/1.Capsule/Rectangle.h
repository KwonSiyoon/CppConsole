#pragma once
class Rectangle
{
public:
    Rectangle();
    ~Rectangle();
    Rectangle(float x, float y);
    float GetArea();
    float GetSize();
private:
    float x = 0;
    float y = 0;

};

