#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <random>

int main() {
	try {
		long long amount = 0;
		std::cout << "Enter amount of array: ";
		if (!(std::cin >> amount) || amount <= 0) throw std::runtime_error("Down!");

		std::random_device rd;
		std::mt19937_64 gen(rd());

		long long* array = new long long[amount];

		for (long long i = 0; i < amount; ++i) {
			*(array + i) = gen() % 10;
		}

		for (long long i = 0; i < amount; ++i) {
			std::cout << std::setw(3) << std::left << *(array + i) ;
		}
		char elements[100];
		std::cout << "\nWhat need you elements (min or max): ";

		std::cin >> elements;

		long long el;
		long long position = 0;
		if (*elements == 'm' && *(elements + 1) == 'i' && *(elements + 2) == 'n') {
			el = (std::numeric_limits <long long> ::max)();
			for (long long i = 0; i < amount; ++i) {
				if (*(array + i) < el) {
					el = *(array + i);
					position = i;
				}
			}
			std::cout << "\nPosition: " << position + 1 << " Min:" << el;
		}
		else {
			if (*elements == 'm' && *(elements + 1) == 'a' && *(elements + 2) == 'x') {
				el = (std::numeric_limits <long long> ::min)();
				for (long long i = 0; i < amount; ++i) {
					if (*(array + i) > el) {
						el = *(array + i);
						position = i;
					}
				}
				std::cout << "\nPosition: " << position + 1 << " Max: " << el;
			}
		}
		delete[] array;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}