#include <iostream>

int main()
{
	
	const char* message = "C ǥ�� ���̺귯���� ������ �ؽ�Ʈ.\n";		// ���Ͽ� �߰��� ���ڿ�.


	FILE* file = nullptr;											// ���� ��Ʈ�� ��ü ����.


	fopen_s(&file, "Test.txt", "wt");								// ���� ����.

	// ���� ����.
	if (file != nullptr)
	{

		fputs(message, file);										// ���ϴ� �� ����.


		fclose(file);												// ���� �ݱ�.
	}

}