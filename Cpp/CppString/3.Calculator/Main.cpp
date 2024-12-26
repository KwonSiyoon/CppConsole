#include <iostream>


class Calculator {
public:
	int Add(int a, int b) {
		++add;
		return a + b;
	}
	float Divide(float a, float b) {
		++divide;
		return a / b;
	}
	int Substract(int a, int b) {
		++substarct;
		return a - b;
	}
	int Multiply(int a, int b) {
		++multiply;
		return a * b;
	}
	void ShowOperationCount() {
		std::cout << "µ¡¼À: " << add << " ";
		std::cout << "»¬¼À: " << substarct << " ";
		std::cout << "°ö¼À: " << multiply << " ";
		std::cout << "³ª´°¼À: " << divide;
	}
private:
	int add = 0;
	int divide = 0;
	int substarct = 0;
	int multiply = 0;
};

class Printer {
public:
	Printer() {
		temp = nullptr;
	}
	~Printer() {
		if (temp != nullptr) {
			delete[] temp;
		}
	}
	void ShowString() {
		if (temp == NULL) {
			std::cout << "Can¡¯t show the string value\n";
		}
		else {
			std::cout << temp <<"\n";
		}
	}
	void SetString(const char* message) {
		if (temp != nullptr) {
			delete[] temp;
		}
		temp = new char[strlen(message) + 1];
		strcpy_s(temp, strlen(message)+1, message);
	}
private:
	char* temp;
};

int main() {

	Calculator calculator;

	std::cout << "3+5=" << calculator.Add(3, 5) << "\n";
	std::cout << "3/5=" << calculator.Divide(3, 5) << "\n";
	std::cout << "12-7=" << calculator.Substract(12, 7) << "\n";
	std::cout << "12x7=" << calculator.Multiply(12, 7) << "\n";

	calculator.ShowOperationCount();


	Printer printer;
	printer.ShowString();

	printer.SetString("Hello C++");
	printer.ShowString();

	printer.SetString("I Want to be a Good Developer");
	printer.ShowString();
}