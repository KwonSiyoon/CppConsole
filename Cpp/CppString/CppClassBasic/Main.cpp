#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

// 클래스 선언.
class Player
{
public:
	// 클래스 이름과 똑같이 생긴 생성자.
	Player()
		: x(0), y(0), speed(1)
	{
		std::cout << "생성자 호출\n";
	}

	// 소멸자.
	~Player()
	{
		std::cout << "소멸자 호출\n";
	}

	// 이동할 만큼의 양을 입력 받아서 좌표를 이동시키는 함수.
	void Move(int x, int y)
	{
		this->x += x;
		this->y += y;
	}

	// 변수
private:
	int x;
	int y;
	int speed;
};


int main() 
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(156);

	// 객체/개체/오브젝트/인스턴스.
	Player player = Player();
	player.Move(10, 20);

	// 동적 할당.
	Player* player2 = new Player();
	delete player2;
	//delete player2;
	//player2 = nullptr;

	std::cin.get();
	return 0;
}