#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>


int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	std::string entry;
	int temp = 0;
	
	do {
		temp = 0;
		std::cout << "Введите строку: ";
		std::cin >> entry;
		for (char i : entry) {
			temp += static_cast<int>(abs(i));
		}
		std::cout << "Наивный хэш строки " << entry << " = " << temp << std::endl;
	} while (entry != "exit");

	return 0;
}