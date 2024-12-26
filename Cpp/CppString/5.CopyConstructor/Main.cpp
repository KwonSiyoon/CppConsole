#include <iostream>

class Player 
{
public:
	// �����ڰ� �ϳ��� ������ �⺻������ �˾Ƽ� �������.
	Player()
		: x(0), y(0)
	{
		//std::cout << "Player() called\n";

		// ���ڿ� ���� ���ϱ�.
		size_t length = strlen("Player") + 1;
		// ���� Ȯ��.
		name = new char[length];
		// ���ڿ� ����.
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
		// ���ڿ� ���� ���ϱ�.
		size_t length = strlen(name) + 1;
		// ���� Ȯ��.
		this->name = new char[length];
		// ���ڿ� ����.
		strcpy_s(this->name, length, name);
	}

	// ���� ������.
	// c++ value category
	// ��������ڸ� �������� �ʾƵ� �˾Ƽ� �ϳ� �������.
	Player(const Player& other)
	{
		std::cout << "Player(const Player& other) called\n";
		
		x = other.x;
		y = other.y;

		// ���ڿ� ���� ���ϱ�.
		size_t length = strlen(other.name) + 1;
		// ���� Ȯ��.
		this->name = new char[length];
		// ���ڿ� ����.
		strcpy_s(this->name, length, other.name);
	}

	~Player()
	{
		// �� �޸� ����.
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
	//Player player1; // Player() �⺻ ������ ȣ��.
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