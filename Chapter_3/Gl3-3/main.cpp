#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <limits>
#include <random>

int main() {
	try {
		long long rows, cols;
		std::cout << "Enter amount of rows: ";
		if (!(std::cin >> rows) || rows <= 0) throw std::runtime_error("Down!");
		std::cout << "Enter amount of cols: ";
		if (!(std::cin >> cols) || cols <= 0) throw std::runtime_error("Down!");

		long long* matrix = new long long [rows * cols];

		/*for (long long i = 0; i < rows; ++i) {
			*(matrix + i) = new long long[cols];
		}
		*/
		std::random_device rd;
		std::mt19937_64 gen(rd());
		//std::uniform_int_distribution <long long> dis((std::numeric_limits <long long> ::min)(), (std::numeric_limits <long long> ::max)());

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				*((matrix + i * cols) + j) = gen() % 10;
			}
		}
		std::cout << "\n";

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < rows; ++j) {
				std::cout << *((matrix + i * cols) + j) << " ";
			}
			std::cout << "\n";
		}

		std::cout << "\n";

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < rows; ++j) {
				std::cout << std::left << std::setw(3) << *((matrix + i * cols) + j) * *((matrix + i * cols) + j) << " ";
			}
			std::cout << "\n";
		}

		std::cout << "\n";
		long long sum = 0;

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < rows; ++j) {
				sum += *((matrix + i* cols) + j) * *((matrix + i * cols) + j);
			}
		}

		delete[] matrix;

		std::cout << "Sum of elements of matrix: " << sum;

	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}