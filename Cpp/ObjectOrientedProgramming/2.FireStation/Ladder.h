#pragma once


class Ladder
{
public:
    Ladder(float length = 0.0f)
        : length(length)
    {

    }

    // Getter/Setter.
    float GetLength() const { return length; }
    void SetLength(float length) { this->length = length; }

private:
    float length = 0.0f;


};
