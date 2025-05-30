// 스마트 포인터 사용을 위한 헤더 추가
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
		std::cout << "생성자 호출\n";
	}
	~Resource()
	{
		std::cout << "소멸자 호출\n";
	}
	void Use()
	{
		std::cout << "자원 사용\n";
	}

};


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	//Resource* resource1 = new Resource();
	resource->Use();

	
	std::unique_ptr<Resource> resource2 = std::move(resource);
	
	resource2->Use();
	
	// Raw 포인터 get
	Resource* rawPointer = resource2.get();
	rawPointer->Use();

	resource = nullptr;
	resource->Use();

	Resource& refResource = *resource2;



	std::shared_ptr<Resource> resourceS = std::make_shared<Resource>();
	std::shared_ptr<Resource> resourceS2 = resourceS;

	std::cout << resourceS.use_count() << "\n";
	std::shared_ptr<Resource> resourceS3 = resourceS;
	std::cout << resourceS.use_count() << "\n";

}