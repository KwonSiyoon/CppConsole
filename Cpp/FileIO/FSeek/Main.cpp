#include <iostream>
#include <fstream>
//#define WriteLine(x) std::cout << x << std::endl

template<typename T>
void WriteLine(const T& value)
{
	std::cout << value << std::endl;
}

// ���� ���ڸ� ó���� �� �ִ� ����
//template<typename... Args>
//void WriteLine(const Args&... args)
//{
//	(std::cout << ... << args) << std::endl;
//}


int main()
{
	
	//const char* stringValue = "id: 10 name: seyunjang balance: 1000000";				// �׽�Ʈ ���ڿ�.

	//int id = 0;																			// ���ڿ����� Ư�� �� ��������
	//char name[256];
	//int balance = 0;

	//sscanf_s(stringValue, "id: %d name: %s balance: %d", &id, name, 256, &balance);

	//std::cout << "id: " << id << "\n";
	//std::cout << "name: " << name << "\n";
	//std::cout << "balance: " << balance << "\n";



	// ������ ����.
	int id = 10;
	const char* name = "ronniejang";
	int balance = 5000000;

	// ���ڿ��� �����.
	char data[1024] = {};											// ������ ����.
	snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);

	// �׽�Ʈ ���.
	//std::cout << data << "\n";

	// ���Ϸ� ����.
	//FILE* file = nullptr;
	//fopen_s(&file, "AccountData.txt", "wb");
	//size_t length = strlen(data);
	//if (file != nullptr)
	//{
	//	//fwrite(data, 1024, 1, file);
	//	fwrite(data, length, 1, file);
	//	fclose(file);
	//}


	// ���� �б�.
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

			// ���ڿ� ��ġ��.
			strcat_s(total, buffer);
		}

		std::cout << total << "\n";

		// �� ��������.
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

	//FILE* file = nullptr;						// ����

	//fopen_s(&file, "Test.txt", "rt");			// ���� ����.

	//if (file != nullptr)						// ����ó��.
	//{
	//	// ó������ 24����Ʈ �̵�.
	//	fseek(file, 24, SEEK_SET);				// ���� ����(Random Access)

	//	char buffer[256];						// ����
	//	while (!feof(file))						// ������ ������ feof(file) == true
	//	{
	//		fgets(buffer, 256, file);			// ������ �б�.

	//		std::cout << buffer;				// ���.
	//	}
	//	

	//	fclose(file);							// ���� �ݱ�.
	//}
}