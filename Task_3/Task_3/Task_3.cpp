#include <iostream>
#include <string>
#include <Windows.h>

std::string request_source_str() {
	std::string source_str;
	std::cout << "Введите строку, в которой будет осуществляться поиск: ";
	std::cin >> source_str;
	return source_str;
}

std::string request_find_str() {
	std::string str_find;
	std::cout << "Введите подстроку, которую нужно найти: ";
	std::cin >> str_find;
	return str_find;
}

unsigned long get_hash(std::string text, int start, int finish) {
		
	int b = 13,
		q = 256;
	unsigned long mult = 1,
				  hash = 0;

	for (int i = start; i < finish; i++) {
		hash += ((mult * static_cast<int>(text[i])) % q);
		mult = mult * b;
	}
	return hash;
}

int search_str(std::string source_str, std::string find_str) {

	int s_size = source_str.size(),
		f_size = find_str.size();
		
	unsigned long s_hash = 0,
				  f_hash = 0;

	f_hash = get_hash(find_str, 0, f_size - 1);

	for (int i = 0; i < s_size - (f_size - 1); i++) {
		s_hash = get_hash(source_str, i, i + (f_size - 1));
		if (s_hash == f_hash) {
			int count = 0;
			for (int j = 0; j < f_size; j++) {
				if (source_str[i + j] == find_str[j]) {
					count++;
				}				
			}
			if (count == f_size) {
				return i;
			}
		}
	}
	return -1;
}

int main(int argc, char** argv) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string find_str,
				source_str;

	source_str = request_source_str();
	do {	
		find_str = request_find_str();
		int i = search_str(source_str, find_str);
		if (i >= 0) {
			std::cout << "Подстрока " << find_str << " найдена по индексу " << i << std::endl;
		}
		else {
			std::cout << "Подстрока " << find_str << " не найдена " << std::endl;
		}
	} while (find_str != "exit");

	return 0;
}