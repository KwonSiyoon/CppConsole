#include <iostream>

class Player 
{
public:
	// 생성자가 하나도 없으면 기본생성자 알아서 만들어줌.
	Player()
		: x(0), y(0)
	{
		//std::cout << "Player() called\n";

		// 문자열 길이 구하기.
		size_t length = strlen("Player") + 1;
		// 공간 확보.
		name = new char[length];
		// 문자열 복사.
		strcpy_s(name, length, "Player");
	}
	/*Player(int number) 
		: x(number), y(number)
	{
		std::cout << "Player(int number) called\n";
	}*/
	Player(const char* name, int x, int y)
		: x(x), y(y)
	{
		// 문자열 길이 구하기.
		size_t length = strlen(name) + 1;
		// 공간 확보.
		this->name = new char[length];
		// 문자열 복사.
		strcpy_s(this->name, length, name);
	}

	// 복사 생성자.
	// c++ value category
	// 복사생성자를 선언하지 않아도 알아서 하나 만들어줌.
	Player(const Player& other)
	{
		std::cout << "Player(const Player& other) called\n";
		
		x = other.x;
		y = other.y;

		// 문자열 길이 구하기.
		size_t length = strlen(other.name) + 1;
		// 공간 확보.
		this->name = new char[length];
		// 문자열 복사.
		strcpy_s(this->name, length, other.name);
	}

	~Player()
	{
		// 힙 메모리 해제.
		delete[] name;
	}

	void Print()
	{
		std::cout << "name: " << name << " x: " << x << ", y : " << y << "\n";
	}

private:
	int x;
	int y;
	char* name;
};


int main() 
{
	//Player player1; // Player() 기본 생성자 호출.
	//Player player2 = Player(10);
	//Player player3 = Player(player2);

	//player2.Print();
	//player3.Print();

	Player player1 = Player("Ronnie", 0, 0);
	Player player2 = Player(player1);

	player1.Print();
	player2.Print();

	std::cin.get();
	return 0;
}