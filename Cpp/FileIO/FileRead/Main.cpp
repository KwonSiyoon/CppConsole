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
			/*if (fgets(buffer, 4, file) == nullptr)
			{
				break;
			}*/
			fgets(buffer, 256, file);

			std::cout << buffer;				// ���.
		}

		fclose(file);							// ���� �ݱ�.
	}

}