#pragma once

// 사각형 영역을 표시하는 클래스.
class Bounds
{
public:
    Bounds(int x, int y, int width = 1, int height = 1)
        : x(x), y(y), width(width), height(height)
    {

    }

    // Getter.
    int X() const { return x; }
    int Y() const { return y; }
    int Width() const { return width; }
    int Height() const { return height; }

    int MaxX() const { return x + width; }          // 오른쪽 끝.
    int MaxY() const { return y + height; }         // 아래 끝.
    
    // 겹침 판정 함수.
    bool Intersects(const Bounds& other) const;

private:
    // 왼쪽상단 기준 x,y.
    float x = 0.0f;
    float y = 0.0f;
    float width = 1.0f;
    float height = 1.0f;
};