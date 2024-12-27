#include "Vector2.h"

// <<연산자 오버로딩.
//std::ostream& operator<<(std::ostream& os, const Vector2& vector)
//{
//	os << "(" << vector.GetX() << "," << vector.GetY() << ")\n";
//	return os;
//}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);

	Vector2 result = position.Multiply(speed);
	Vector2 result2 = position * speed;

	std::cout << result << "\n";
	
	result += position;
	std::cout << result << "\n";
	result++;
	std::cout << result << "\n";

	std::cin.get();
}