#include <iostream>
#include "Hashtable.h"

int main()
{
	Hashtable table;

	table.Add("Ronnie", "010-12345678");
	table.Add("Ronnie", "010-37610942");
	table.Add("Kevin", "010-32979287");
	table.Add("Baker", "010-29871982");
	table.Add("Taejun", "010-39487298");

	table.Print();

	//auto find = table.Find("Ronnie");
	//Hashtable::Entry find = {};

	
	Pair<std::string, std::string> value;
	if (table.Find("Baker", value))
	{
		std::cout << "검색 결과: " << value.key << ", " << value.value << std::endl;
	}
	else
	{
		std::cout << "검색 결과: 찾지 못했습니다.";
	}


	/*if (value.value.size() > 0)
	{
		std::cout << "검색 결과: " << value.key << ", " << value.value << std::endl;
	}*/

	table.Delete("Ronnie");
	table.Delete("Baker");

	table.Print();

	std::cin.get();
}