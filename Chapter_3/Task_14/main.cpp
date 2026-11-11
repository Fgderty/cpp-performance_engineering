#include <iostream>
#include <stdexcept>
#include <random>
#include <iomanip>
#include <limits>

int main() {
	try {
		long long rows, cols;;
		std::cout << "Enter rows of matrix: ";
		if (!(std::cin >> rows) || rows <= 0) throw std::runtime_error("Down!");
		std::cout << "Enter cols of matrix: ";
		if (!(std::cin >> cols) || cols <= 0) throw std::runtime_error("Down!");

		long long* matrix = new long long[rows * cols];

		std::random_device rd;
		std::mt19937 gen(rd());

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				*(matrix + i * cols + j) = gen() % 10;
			}
		}

		std::cout << "\nMatrix: \n";

		for (long long i = 0; i < rows; ++i) {
			for (long long j = 0; j < cols; ++j) {
				std::cout << std::setw(3) << std::left << *(matrix + i * cols + j);
			}
			std::cout << "\n";
		}

		while (std::cin.get() != '\n');
		char* elements = new char[100];
		std::cout << "\nWhat need you elements (min or max): ";
		std::cin.getline(elements, 100);

		if (std::cin.fail()) {
			delete[] elements;
			delete[] matrix;
			throw std::runtime_error("Down!");
		}

		bool is_min = false;
		if (*elements == 'm' && *(elements + 1) == 'i' && *(elements + 2) == 'n' && *(elements + 3) == '\0') {
			is_min = true;
		}
		else if (!(*elements == 'm' && *(elements + 1) == 'a' && *(elements + 2) == 'x' && *(elements + 3) == '\0')) {
			delete[] elements;
			delete[] matrix;
			throw std::runtime_error("Down!");
		}

		delete[] elements;

		char* demension = new char[100];
		std::cout << "\nWhat dimension you need (rows or cols): ";
		std::cin.getline(demension, 100);

		if (std::cin.fail()) {
			delete[] demension;
			delete[] matrix;
			throw std::runtime_error("Down!");
		}

		bool is_row_mode = false;

		if (*demension == 'r' && *(demension + 1) == 'o' && *(demension + 2) == 'w' && *(demension + 3) == 's' && *(demension + 4) == '\0') {
			is_row_mode = true;
		}
		else if (!(*demension == 'c' && *(demension + 1) == 'o' && *(demension + 2) == 'l' && *(demension + 3) == 's' && *(demension + 4) == '\0')) {
			delete[] demension;
			delete[] matrix;
			throw std::runtime_error("Down!");
		}

		delete[] demension;

		long long rez_size = is_row_mode ? rows : cols;
		long long* result_array = new long long[rez_size];
		long long count = 0;

		if (is_row_mode) {
			for (long long i = 0; i < rows; ++i) {
				long long extremum = *(matrix + i * cols + 0);

				for (long long j = 1; j < cols; ++j) {
					long long val = *(matrix + i * cols + j);
					if (is_min ? (val < extremum) : (val > extremum)) extremum = val;
				}
				*(result_array + count) = extremum;
				++count;
			}
		}
		else {
			for (long long j = 0; j < cols; ++j) {
				long long extremum = *(matrix + 0 * cols + j);

				for (long long i = 1; i < rows; ++i) {
					long long val = *(matrix + i * cols + j);
					if (is_min ? (val < extremum) : (val > extremum)) extremum = val;
				}
				*(result_array + count) = extremum;
				++count;
			}
		}

		std::cout << "\nResult Array (" << (is_min ? "min" : "max") << " for " << (is_row_mode ? "rows" : "cols") << "):\n";

		for (long long i = 0; i < rez_size; ++i) {
			std::cout << *(result_array + i) << " ";
		}
		std::cout << "\n";

		delete[] result_array;
		delete[] matrix;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}