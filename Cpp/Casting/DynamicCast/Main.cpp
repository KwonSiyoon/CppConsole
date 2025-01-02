#include <iostream>

// Ÿ�� ������ ���� ��ũ��.
// #define ���ٸ� ��ũ�η� �Ǵ�.
// \�� �߰��� ���� �ٱ��� ����.
#define RTTI(name) \
	public:			\
		virtual const char* ClassName() const { return #name; }




class Actor
{
	
	
public:
	RTTI(Actor);
	// ���� �Լ�(Virtual Function).
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
	// ��ü ����.
	Actor* actor = new Actor();
	Player* player = new Player();

	// �� ĳ����(Up Casting)
	//Actor* actorPoint = player;
	Actor* actorPoint = reinterpret_cast<Actor*>(player);

	// OK
	Player* playerPointer = static_cast<Player*>(actorPoint);

	// Not ok.
	// �ٿ�ĳ����
	//Player* player2 = static_cast<Player*>(actor);
	
	// dynamic_cast �ſ� ����. ���Ӻо߿��� ������� ����.
	Player* player2 = dynamic_cast<Player*>(actor); // dynamic_cast => virtual �Լ��� �־�� ��� ����.
	// �Լ� ȣ��.
	//player->PrintValue();
	// ����ó��.
	if (player2)
	{
		player2->PrintValue();
	}
	else
	{
		std::cout << "����ȯ ����.\n";
	}

	// typeid.
	const type_info& info = typeid(actorPoint);
	std::cout << "Ÿ�� �̸�: " << info.name() << "\n";

	std::cout << "Actor Ÿ�� : " << actor->ClassName() << "\n";
	std::cout << "Player Ÿ�� : " << player->ClassName() << "\n";
	std::cout << "actorPoint Ÿ�� : " << actorPoint->ClassName() << "\n";

	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "Ÿ�� ����\n";
	}
	else
	{
		std::cout << "Ÿ�� �ٸ�\n";
	}

}