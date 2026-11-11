#include <iostream>
#include <stdexcept>
#include <limits>
#include <random>
#include <iomanip>
#include <algorithm>

int main() {
	try {
		long long rows1, cols1;
		long long rows2, cols2;
		std::cout << "Enter rows of 1-st matrix: ";
		if (!(std::cin >> rows1) || rows1 <= 0) throw std::runtime_error("Down!");
		std::cout << "\nEnter cols of 1-st matrix: ";
		if (!(std::cin >> cols1) || cols1 <= 0) throw std::runtime_error("Down!");
		std::cout << "\nEnter rows of 2-nd matrix: ";
		if (!(std::cin >> rows2) || rows2 <= 0) throw std::runtime_error("Down!");
		std::cout << "\nEnter cols of 2-nd matrix: ";
		if (!(std::cin >> cols2) || cols2 <= 0) throw std::runtime_error("Down!");

		if(cols1 != rows2) throw std::runtime_error("cols of 1-st matrix must equal rows of 2-nd matrix");

		long long* matrix1 = new long long[rows1 * cols1];
		long long* matrix2 = new long long[rows2 * cols2];
		long long* matrix3 = new long long[cols1 * rows2];

		std::random_device rd;
		std::mt19937_64 gen(rd());

		for (long long i = 0; i < rows1; ++i) {
			for (long long j = 0; j < cols1; ++j) {
				*(matrix1 + i * cols1 + j) = gen() % 10;
			}
		}

		for (long long i = 0; i < rows2; ++i) {
			for (long long j = 0; j < cols2; ++j) {
				*(matrix2 + i * cols2 + j) = gen() % 10;
			}
		}

		std::cout << "Matrix1 :\n";

		for (long long i = 0; i < rows1; ++i) {
			for (long long j = 0; j < cols1; ++j) {
				std::cout << std::setw(3) << std::left << *(matrix1 + i * cols1 + j);
			}
			std::cout << "\n";
		}

		std::cout << "Matrix2 :\n";

		for (long long i = 0; i < rows2; ++i) {
			for (long long j = 0; j < cols2; ++j) {
				std::cout << std::setw(3) << std::left << *(matrix2 + i * cols2 + j);
			}
			std::cout << "\n";
		}

		delete[] matrix1;
		delete[] matrix2;
		delete[] matrix3;

	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}