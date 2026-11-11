#include <iostream>
#include <stdexcept>
#include <random>
#include <iomanip>

int main() {
	try {
		long long rows = 0, cols = 0;
		std::cout << "Enter amount of rows matrix: ";
		if (!(std::cin >> rows) || rows <= 0) throw std::runtime_error("Invalid users!");
		std::cout << "Enter amount of cols matrix: ";
		if (!(std::cin >> cols) || cols <= 0) throw std::runtime_error("Invalid users!");

		long long* matrix = new long long[rows * cols];

		std::random_device rd;
		std::mt19937_64 gen(rd());

		std::cout << "Matrix:\n";

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				*(matrix + i * cols + j) = gen() % 100;
				std::cout << std::setw(4) << std::left << *(matrix + i * cols + j);
			}
			std::cout << "\n";
		}

		long long rows_del, cols_del;
		std::cout << "What row you want to delete:";
		if (!(std::cin >> rows_del) || rows_del < 1 || rows_del > rows) throw std::runtime_error("Invalid users!");
		rows_del -= 1;

		std::cout << "What col you want to delete:";
		if (!(std::cin >> cols_del) || cols_del < 1 || cols_del > cols) throw std::runtime_error("Invalid users!");
		cols_del -= 1;

		for (long long i = 0; i < rows; ++i) {
			bool flag = false;
			for (long long j = 0; j < cols; ++j) {
				if (i == rows_del || j == cols_del) {
					flag = false;
					continue;
				}
				std::cout << std::setw(4) << std::left << *(matrix + i * cols + j);
				flag = true;
			}
			if(flag) std::cout << "\n";
		}
		delete[] matrix;
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << "\n";
		return 1;
	}
	return 0;
}