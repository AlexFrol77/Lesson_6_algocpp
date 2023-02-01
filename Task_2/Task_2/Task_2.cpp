#include <iostream>
#include <string>
#include <Windows.h>

bool simple_string_hash(int p, int n) {
	long temp_hash = 0;
	int mult = 1;

	std::string entry;
	
	std::cout << "Введите строку: ";
	std::cin >> entry;
	for (char i : entry) {	
		temp_hash += mult * static_cast<int>(i);
		mult = mult * p;
	}
	temp_hash %= n;
	std::cout << "Хэш строки " << entry << " = " << temp_hash << std::endl;
	if (entry == "exit") {
		return false;
	}
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int p, n;

	bool flag;

	std::cout << "Введите p: ";
	std::cin >> p;
	std::cout << "Введите n: ";
	std::cin >> n;

	do {
		flag = simple_string_hash(p, n);
	} while (flag);

	return 0;
}