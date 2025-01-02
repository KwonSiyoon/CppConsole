#include <iostream>
#include <fstream>
//#define WriteLine(x) std::cout << x << std::endl

template<typename T>
void WriteLine(const T& value)
{
	std::cout << value << std::endl;
}

// 여러 인자를 처리할 수 있는 버전
//template<typename... Args>
//void WriteLine(const Args&... args)
//{
//	(std::cout << ... << args) << std::endl;
//}


int main()
{
	
	//const char* stringValue = "id: 10 name: seyunjang balance: 1000000";				// 테스트 문자열.

	//int id = 0;																			// 문자열에서 특정 값 가저오기
	//char name[256];
	//int balance = 0;

	//sscanf_s(stringValue, "id: %d name: %s balance: %d", &id, name, 256, &balance);

	//std::cout << "id: " << id << "\n";
	//std::cout << "name: " << name << "\n";
	//std::cout << "balance: " << balance << "\n";



	// 데이터 쓰기.
	int id = 10;
	const char* name = "ronniejang";
	int balance = 5000000;

	// 문자열로 만들기.
	char data[1024] = {};											// 저장할 버퍼.
	snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);

	// 테스트 출력.
	//std::cout << data << "\n";

	// 파일로 생성.
	//FILE* file = nullptr;
	//fopen_s(&file, "AccountData.txt", "wb");
	//size_t length = strlen(data);
	//if (file != nullptr)
	//{
	//	//fwrite(data, 1024, 1, file);
	//	fwrite(data, length, 1, file);
	//	fclose(file);
	//}


	// 파일 읽기.
	FILE* file = nullptr;
	fopen_s(&file, "AccountData.txt", "rb");
	if (file != nullptr)
	{
		char total[2048] = {};
		char buffer[1024];
		while (!feof(file))
		{
			fgets(buffer, 1024, file);

			//std::cout << buffer;

			// 문자열 합치기.
			strcat_s(total, buffer);
		}

		std::cout << total << "\n";

		// 값 가져오기.
		int id1 = 0;
		char namebuffer[256] = {};
		int balance1 = 0;

		sscanf_s(total, "id: %d name: %s balance: %d", &id1, namebuffer, 256, &balance1);

		std::cout << id1 << "\n";
		std::cout << namebuffer << "\n";
		std::cout << balance1 << "\n";
		WriteLine(id1);

	}




	//char buffer[1024];


	//std::ofstream output;
	//std::ifstream input;

	//FILE* file = nullptr;						// 파일

	//fopen_s(&file, "Test.txt", "rt");			// 파일 열기.

	//if (file != nullptr)						// 예외처리.
	//{
	//	// 처음에서 24바이트 이동.
	//	fseek(file, 24, SEEK_SET);				// 임의 접근(Random Access)

	//	char buffer[256];						// 버퍼
	//	while (!feof(file))						// 파일이 끝나면 feof(file) == true
	//	{
	//		fgets(buffer, 256, file);			// 데이터 읽기.

	//		std::cout << buffer;				// 출력.
	//	}
	//	

	//	fclose(file);							// 파일 닫기.
	//}
}