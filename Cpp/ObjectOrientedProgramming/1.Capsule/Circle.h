#pragma once
class Circle
{
public:
    Circle();
    ~Circle();
    Circle(float r);
    float GetArea();
    float GetSize();
private:
    float r = 0;
    
};

