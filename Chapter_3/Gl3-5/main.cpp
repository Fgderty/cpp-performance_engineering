#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <random>

int main() {
	try {
		long long rows, cols;
		std::cout << "Enter rows of matrix: ";
		if (!(std::cin >> rows) || rows <= 0) throw std::runtime_error("Down!");
		std::cout << "Enter cols of matrix: ";
		if (!(std::cin >> cols) || cols <= 0) throw std::runtime_error("Down!");

		long long* matrix = new long long[rows * cols];

		std::random_device rd;
		std::mt19937_64 gen(rd());
		//std::uniform_int_distribution <long long> dis((std::numeric_limits <long long> ::min)(), (std::numeric_limits <long long> ::max)());

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				*(matrix + i * cols + j) = gen() % 10;
			}
		}

		std::cout << "\n";

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				std::cout << std::setw(2) << std::left << *(matrix + i * cols + j);
			}
			std::cout << "\n";
		}

		std::cout << "\n";
		
		std::cout << "Matrix rotate 90 right:";

		std::cout << "\n";

		long long* base_ptr = matrix + (rows - 1) * cols;

		for (long long shift = 0; shift < cols; ++shift) {
			for (long long* current = base_ptr + shift; current >= matrix + shift; current -= cols) {
				std::cout << std::setw(2) << std::left << *current;
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