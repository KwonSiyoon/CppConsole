#include <iostream>

// 타입 정보를 위한 매크로.
// #define 한줄만 매크로로 판단.
// \를 추가시 다음 줄까지 포함.
#define RTTI(name) \
	public:			\
		virtual const char* ClassName() const { return #name; }




class Actor
{
	
	
public:
	RTTI(Actor);
	// 가상 함수(Virtual Function).
	virtual void PrintValue()
	{
		std::cout << "Value: " << a << "\n";
	}
	

protected:
	int a;

};

class Player : public Actor
{
	RTTI(Player);
};



int main()
{
	// 객체 생성.
	Actor* actor = new Actor();
	Player* player = new Player();

	// 업 캐스팅(Up Casting)
	//Actor* actorPoint = player;
	Actor* actorPoint = reinterpret_cast<Actor*>(player);

	// OK
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok.
	// 다운캐스팅
	//Player* player2 = static_cast<Player*>(actor);
	
	// dynamic_cast 매우 느림. 게임분야에서 사용하지 않음.
	Player* player2 = dynamic_cast<Player*>(actor); // dynamic_cast => virtual 함수가 있어야 사용 가능.
	// 함수 호출.
	//player->PrintValue();
	// 예외처리.
	if (player2)
	{
		player2->PrintValue();
	}
	else
	{
		std::cout << "형변환 실패.\n";
	}

	// typeid.
	const type_info& info = typeid(actorPoint);
	std::cout << "타입 이름: " << info.name() << "\n";

	std::cout << "Actor 타입 : " << actor->ClassName() << "\n";
	std::cout << "Player 타입 : " << player->ClassName() << "\n";
	std::cout << "actorPoint 타입 : " << actorPoint->ClassName() << "\n";

	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "타입 동일\n";
	}
	else
	{
		std::cout << "타입 다름\n";
	}

}