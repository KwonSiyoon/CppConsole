#include <iostream>


int main()
{
	
	char buffer[256];							// �о�� �����.

	FILE* file = nullptr;						// ���� ��Ʈ�� ��ü ����.

	fopen_s(&file, "Test.txt", "rt");			// ���� ����.

	// ���� �б�.
	if (file != nullptr)
	{
		// ���ۿ� ���� �о���̱�.
		// feof() ������ �ٷ� �� ���� ��ġ�� ������� �˷��ִ� �Լ�.
		while (!feof(file))						// ������ ������ ������ true ��ȯ
		{
			if (fgets(buffer, 256, file) != nullptr)
			{
				std::cout << buffer;			// ���.
			}
			//fgets(buffer, 256, file);

							
		}

		fclose(file);							// ���� �ݱ�.
	}

}