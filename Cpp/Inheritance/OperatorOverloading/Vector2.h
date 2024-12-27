#pragma once

#include <iostream>

// 2���� ���� Ŭ����
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y = 0.0f);

	// ���ϱ�.
	Vector2 Add(const Vector2& other);

	// ���ϱ�.
	Vector2 Multiply(const Vector2& other);

	// ������ �����ε�.
	// Ư���� �Լ�.
	Vector2 operator+(const Vector2& other);
	Vector2 operator*(const Vector2& other);
	void operator+=(const Vector2& other);
	void operator++(int num);

	// ��ü ������ �����ε� �Ϸ��� friend ���̸� ��.
	// �ܺ� ��ü�� ����ϱ� ����.
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

