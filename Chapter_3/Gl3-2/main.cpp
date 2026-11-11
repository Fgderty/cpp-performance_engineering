#include <iostream>
#include <stdexcept>
#include <random>
#include <limits>
#include <iomanip>

int main() {
	try {
		long long size = 0;
		std::cout << "Enter length array: ";
		if (!(std::cin >> size)) throw std::runtime_error("Down!");

		long long* arr1 = new long long[size];
		std::random_device rd;
		std::mt19937_64 gen(rd());
		/*std::uniform_int_distribution <long long> dis((std::numeric_limits <long long> ::min)(),
													  (std::numeric_limits <long long> ::max)());
		*/

		for (long long i = 0; i < size; ++i) {
			*(arr1 + i) = gen() % 101;
		}

		for (long long i = 0; i < size; ++i) {
			std::cout << std::left << std::setw(7) << *(arr1+ i);
		}

		std::cout << "\n";

		for (long long i = 0; i < size; ++i) {
			*(arr1 + i) = *(arr1 + i) * *(arr1 + i);
		}

		for (long long i = 0; i < size; ++i) {
			std::cout << std::left << std::setw(7) << *(arr1 + i);
		}

		std::cout << "\n";

		long long sum = 0;

		for (long long i = 0; i < size; ++i) {
			sum += *(arr1 + i);
		}

		std::cout << "Sum of elements: " << sum;

		delete[] arr1;
		arr1 = nullptr;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";

	return 0;
}