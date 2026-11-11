#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <random>
#include <limits>

int main() {
	try {
		long long size = 0;
		std::cout << "Enter size of square matrix: ";
		if (!(std::cin >> size) || size <= 0) throw std::runtime_error("Down!");

		long long* matrix = new long long[size * size];

		std::random_device rd;
		std::mt19937_64 gen(rd());
		//std::uniform_int_distribution <long long> dis((std::numeric_limits <long long> ::min)(), (std::numeric_limits <long long> ::max)());

		for (long long i = 0; i < size; ++i) {
			for (long long j = 0; j < size; ++j) {
				*(matrix + i * size + j) = gen() % 10;
			}
		}

		std::cout << "\n";

		for (long long i = 0; i < size; ++i) {
			for (long long j = 0; j < size; ++j) {
				std::cout << std::setw(3) << std::left << *(matrix + i * size + j);
			}
			std::cout << "\n";
		}

		for (long long i = 0; i < size; ++i) {
			for (long long j = 0; j < size; ++j) {
				*(matrix + i * size + j) = 0;
			}
		}

		std::cout << "New matrix: \n";

		for (long long i = 0; i < size; ++i) {
			*(matrix + i * size + i) = 1;
			*(matrix + i * size + (size - 1 - i)) = 1;
		}

		for (long long i = 0; i < size; ++i) {
			for (long long j = 0; j < size; ++j) {
				std::cout << std::setw(3) << std::left << *(matrix + i * size + j);
			}
			std::cout << "\n";
		}

		delete[] matrix;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}