#include <iostream>
#include <stdexcept>
#include <random>
#include <iomanip>

int main() {
	try {
		long long len1 = 0, len2 = 0, rep = 0;
		std::cout << "Enter length of 1-st Array: ";
		if (!(std::cin >> len1) || len1 <= 0) throw std::runtime_error("Invalid length for first array!");
		std::cout << "Enter length of 2-nd Array: ";
		if (!(std::cin >> len2) || len2 <= 0) throw std::runtime_error("Invalid length for second array!");
		std::cout << "Enter number of repetions: ";
		if (!(std::cin >> rep) || rep <= 0) throw std::runtime_error("Invalid length for second array!");

		long long sum_len = len1 + len2;
		long long len3 = sum_len * rep;
		long long* arr = new long long[len3];

		std::random_device rd;
		std::mt19937_64 gen(rd());

		std::cout << "Array 1:\n";
		for (long long i = 0; i < len1; ++i) {
			*(arr + i) = gen() % 100;
			std::cout << std::setw(4) << std::left << *(arr + i);
		}
		std::cout << "\nArray 2:\n";
		for (long long j = len1; j < sum_len; ++j) {
			*(arr + j) = gen() % 100;
			std::cout << std::setw(4) << std::left << *(arr + j);
		}

		std::cout << "\nEnter what array to be 1-st or 2-nd (1 or 2): ";
		char ch;
		if (!(std::cin >> ch) || (ch != '1' && ch != '2')) throw std::runtime_error("Invalid users");

		switch (ch) {
			case '1':
				for (long long k = 0; k < rep; ++k) {
					for (long long i = 0; i < len1; ++i) {
						*(arr + i + k * sum_len) = *(arr + i);
						std::cout << std::setw(4) << std::left << *(arr + i + k * sum_len);
					}
					for (long long j = len1; j < sum_len; ++j) {
						*(arr + j + k * sum_len) = *(arr + j);
						std::cout << std::setw(4) << std::left << *(arr + j + k * sum_len);
					}
				}
				break;

			case '2':
				for (long long k = 0; k < rep; ++k) {
					for (long long j = len1; j < sum_len; ++j) {
						*(arr + j + k * sum_len) = *(arr + j);
						std::cout << std::setw(4) << std::left << *(arr + j + k * sum_len);
					}
					for (long long i = 0; i < len1; ++i) {
						*(arr + i + k * sum_len) = *(arr + i);
						std::cout << std::setw(4) << std::left << *(arr + i + k * sum_len);
					}
				}
				break;
		}
		std::cout << "\n";
		delete[] arr;
		arr = nullptr;
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << "\n";
		return 1;
	}
	return 0;
}