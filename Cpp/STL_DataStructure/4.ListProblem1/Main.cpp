#include <iostream>
#include <list>
#include <stack>

struct Vector2
{
    Vector2() {};
    ~Vector2() {};
    Vector2(const wchar_t name, int x, int y)
        : name(name), x(x), y(y)
    {};

    int x = 0;
    int y = 0;
    wchar_t name = 'a';
};

std::ostream& operator<<(std::ostream& os, const Vector2& vector)
{
    return os << (char)vector.name << " ( " << vector.x << ", " << vector.y << " )\n";
}


int main()
{
    std::list<Vector2> dotList;
    dotList.push_back(Vector2('A', 50, 200));
    dotList.push_back(Vector2('B', 20, 80));
    dotList.push_back(Vector2('C', 75, 10));
    dotList.push_back(Vector2('D', 130, 80));
    dotList.push_back(Vector2('E', 100, 200));
    for (auto& iter : dotList)
    {
        std::cout << iter;
    }
    std::cout << "출력 완료\n";
    
    std::list<Vector2>::iterator iter1 = dotList.end();
    --iter1;
    dotList.insert(iter1, Vector2('F', 180, 150));
    for (auto& iter : dotList)
    {
        std::cout << iter;
    }
    std::cout << "출력 완료\n";
}