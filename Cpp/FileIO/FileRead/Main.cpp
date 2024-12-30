#include <iostream>


int main()
{
	
	char buffer[256];							// 읽어올 저장소.

	FILE* file = nullptr;						// 파일 스트림 객체 선언.

	fopen_s(&file, "Test.txt", "rt");			// 파일 열기.

	// 파일 읽기.
	if (file != nullptr)
	{
		// 버퍼에 내용 읽어들이기.
		// feof() 파일을 다룰 때 현재 위치가 어디인지 알려주는 함수.
		while (!feof(file))						// 파일을 끝까지 읽으면 true 반환
		{
			/*if (fgets(buffer, 4, file) == nullptr)
			{
				break;
			}*/
			fgets(buffer, 256, file);

			std::cout << buffer;				// 출력.
		}

		fclose(file);							// 파일 닫기.
	}

}