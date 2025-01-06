// ����Ʈ ������ ����� ���� ��� �߰�
#include <memory>
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


class Resource
{
public:
	Resource()
	{
		std::cout << "������ ȣ��\n";
	}
	~Resource()
	{
		std::cout << "�Ҹ��� ȣ��\n";
	}
	void Use()
	{
		std::cout << "�ڿ� ���\n";
	}

};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::shared_ptr<Resource> resourceS = std::make_shared<Resource>();
	std::shared_ptr<Resource> resourceS2 = resourceS;

	std::cout << resourceS.use_count() << "\n";
	std::shared_ptr<Resource> resourceS3 = resourceS; 
	{
		std::shared_ptr<Resource> resourceS4 = resourceS;
		std::cout << resourceS.use_count() << "\n";
	}
	std::cout << resourceS.use_count() << "\n";

}