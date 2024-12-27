#include "Entity.h"
#include "Player.h"
#include <iostream>

int main()
{
	// Entity 객체 생성.
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player 객체 생성.
	//Player* player = new Player("Ronnie");
	IEntity* player = new Player("Ronnie");
	std::cout << player->GetName() << "\n";

	// 다형성.
	//Entity* entity2 = player; // 자식을 부모에 저장가능. Upcasting.

	// World -> Level(Scene) -> Actor.
	// Level(Scene) = Actor[] 
	// Level -> Actor(물체) 들의 모임.
	// class TestActor : public Actor {}
	// AddActor(Actor* actor);
	// TestActor* test = new TestActor();
	// AddActor(test); -> test를 TestActor에서 Actor로 upcasting하여 Actor[]에 추가하여 저장.
	// 형변환 실패시 nullptr.

	//delete entity;
	delete player;

	std::cin.get();
}