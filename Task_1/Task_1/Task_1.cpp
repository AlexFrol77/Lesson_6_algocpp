#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

bool simple_string_hash() {
	int temp = 0;
	std::string entry;
	std::cout << "Введите строку: ";
	std::cin >> entry;
	for (char i : entry) {
		temp += static_cast<int>(abs(i));
	}
	std::cout << "Наивный хэш строки " << entry << " = " << temp << std::endl;
	if (entry == "exit") {
		return false;
	}
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	bool flag;

	do {
		flag = simple_string_hash();
	} while (flag);

	return 0;
}