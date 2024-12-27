#pragma once

#include <iostream>

// 2차원 벡터 클래스
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y = 0.0f);

	// 더하기.
	Vector2 Add(const Vector2& other);

	// 곱하기.
	Vector2 Multiply(const Vector2& other);

	// 연산자 오버로딩.
	// 특별한 함수.
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	void operator+=(const Vector2& other);
	void operator++(int num);

	// 객체 내에서 오버로딩 하려면 friend 붙이면 됨.
	// 외부 객체를 써야하기 때문.
	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector)
	{
		os << "(" << vector.GetX() << "," << vector.GetY() << ")\n";
		return os;
	}

	// Getter/Setter.
	float GetX() const;
	float GetY() const;

private:
	float x, y;

};

