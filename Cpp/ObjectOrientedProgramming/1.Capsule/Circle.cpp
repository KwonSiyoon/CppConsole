#include "Circle.h"
#define _USE_MATH_DEFINES
#include "math.h"

Circle::Circle()
{
}

Circle::~Circle()
{
}

Circle::Circle(float r)
    : r(r)
{
}

float Circle::GetArea()
{
    //return r*r*3.14f;
    return r*r*(float)M_PI;
}

float Circle::GetSize()
{
    //return r*2.0f*3.14f;
    return r*2.0f* (float)M_PI;
}
