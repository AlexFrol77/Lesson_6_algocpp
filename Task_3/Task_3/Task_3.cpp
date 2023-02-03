#include <iostream>
#include <string>
#include <cmath>
#include <Windows.h>

std::string request_str_temp() {
	std::string source_str;
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> source_str;
	return source_str;
}

std::string request_str_find() {
	std::string str_find;
	std::cout << "Введите подстроку, которую нужно найти: ";
	std::cin >> str_find;
	return str_find;
}

int search_str(std::string source_str, std::string find_str, int s_size, int f_size) {
	long long find_hash = 0,
			  source_hash = 0;
	int p = 256,
		n = 1001,
		mult = 1;
	for (int i = 0; i < source_str.size() - f_size; i++) {
		if (i == 0) {
			for (int j = 0; j < f_size - 1; j++) {
				find_hash += ((find_hash * p + static_cast<int>(find_str[j])) % n);
				source_hash += ((source_hash * p + static_cast<int>(source_str[j])) % n);
			}
		}
		else {
			source_hash -= (static_cast<int>(source_str[i - 1]) % n);
			source_hash += ((source_hash * (long long)pow(p, (f_size - 1)) + static_cast<int>(source_str[i + (f_size - 1)]))) % n;
				
		}
		if (find_hash == source_hash) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string find_str = "ohel",
		source_str = "hellohelomydearfriendhello";

	int hash_find,
		find_size = find_str.size(),
		source_size = source_str.size();

	
	int i = search_str(source_str, find_str, source_size, find_size);
	if (i >= 0) {
		std::cout << "Подстрока " << find_str << " найдена по индексу " << i << std::endl;
	}
	else {
		std::cout << "Подстрока " << find_str << " не найдена " << std::endl;
	}
	return 0;
}