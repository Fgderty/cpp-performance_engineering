#include <iostream>
#include <stdexcept>
#include <random>
#include <iomanip>

int main() {
	try {
		std::random_device rd;
		std::mt19937_64 gen(rd());

		long long length = gen() % 26;
		long long* array = new long long[length];

		for (long long i = 0; i < length; ++i) {
			*(array + i) = gen() % 10;
		}

		std::cout << "Array:\n";

		for (long long i = 0; i < length; ++i) {
			std::cout << std::setw(3) << std::left << *(array + i);
		}

		long long left = 0;
		long long right = length - 1;

		for (long long i = 1; left <= right; ++i, ++left, --right) {
			*(array + left) = i;
			*(array + right) = i;
		}

		std::cout << "\nNEW Array:\n";

		for (long long i = 0; i < length; ++i) {
			std::cout << std::setw(4) << std::left << *(array + i);
		}

		delete[] array;
	}
	catch (const std::runtime_error& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}