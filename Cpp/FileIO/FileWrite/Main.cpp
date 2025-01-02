#include <iostream>

int main()
{
	
	const char* message = "C 표준 라이브러리로 생성한 텍스트.\n";		// 파일에 추가할 문자열.


	FILE* file = nullptr;											// 파일 스트림 객체 선언.


	fopen_s(&file, "Test.txt", "wt");								// 파일 열기.

	// 파일 쓰기.
	if (file != nullptr)
	{

		fputs(message, file);										// 원하는 값 쓰기.


		fclose(file);												// 파일 닫기.
	}

}