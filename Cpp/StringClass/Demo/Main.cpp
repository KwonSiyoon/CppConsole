#include "String.h"

int main()
{
	String string("Ronnie");

	std::cout << string << "\n";

	string = "abcd";
	std::cout << string << "\n";
	std::cout << string.Length() << "\n";

	std::cout << ((string == "dcba") ? "True" : "False") << "\n";
	String result = string == "Ronnie" ? "true" : "false";
	const char* result2 = string == "Ronnie" ? "true" : "false";
	std::cout << result << "\n";
	std::cout << result2 << "\n";

	std::cin.get();
}
