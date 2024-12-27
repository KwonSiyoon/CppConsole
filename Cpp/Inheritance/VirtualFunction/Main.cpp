#include "Entity.h"
#include "Player.h"
#include <iostream>

int main()
{
	// Entity ��ü ����.
	//Entity* entity = new Entity();
	//std::cout << entity->GetName() << "\n";

	// Player ��ü ����.
	//Player* player = new Player("Ronnie");
	IEntity* player = new Player("Ronnie");
	std::cout << player->GetName() << "\n";

	// ������.
	//Entity* entity2 = player; // �ڽ��� �θ� ���尡��. Upcasting.

	// World -> Level(Scene) -> Actor.
	// Level(Scene) = Actor[] 
	// Level -> Actor(��ü) ���� ����.
	// class TestActor : public Actor {}
	// AddActor(Actor* actor);
	// TestActor* test = new TestActor();
	// AddActor(test); -> test�� TestActor���� Actor�� upcasting�Ͽ� Actor[]�� �߰��Ͽ� ����.
	// ����ȯ ���н� nullptr.

	//delete entity;
	delete player;

	std::cin.get();
}