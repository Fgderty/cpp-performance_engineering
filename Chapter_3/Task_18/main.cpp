#include <iostream>
#include <stdexcept>
#include <random>
#include <iomanip>

int main() {
	try {
		long long len1 = 0, len2 = 0;
		std::cout << "Enter length of 1-st Array: ";
		if (!(std::cin >> len1) || len1 <= 0) throw std::runtime_error("Invalid length for first array!");
		std::cout << "Enter length of 2-nd Array: ";
		if (!(std::cin >> len2) || len2 <= 0) throw std::runtime_error("Invalid length for second array!");

		long long len3 = len1 + len2;
		long long* arr = new long long[len3];

		std::random_device rd;
		std::mt19937_64 gen(rd());

		std::cout << "Array 1:\n";
		for (long long i = 0; i < len1; ++i) { 
			*(arr + i) = gen() % 100;
			std::cout << std::setw(4) << std::left << *(arr + i);
		}
		std::cout << "\nArray 2:\n";
		for (long long j = len1; j < len3; ++j) { 
			*(arr + j) = gen() % 100;
			std::cout << std::setw(4) << std::left << *(arr + j);
		}

		std::cout << "\nEnter what array to be 1-st or 2-nd (1 or 2): ";
		char ch;
		if (!(std::cin >> ch) || (ch != '1' && ch != '2')) throw std::runtime_error("Invalid users");

		switch (ch) {
			case '1':
				for (long long i = 0; i < len1; ++i) std::cout << std::setw(4) << std::left << *(arr + i);
				for (long long j = len1; j < len3; ++j) std::cout << std::setw(4) << std::left << *(arr + j);
				break;
			case '2':
				for (long long j = len1; j < len3; ++j) std::cout << std::setw(4) << std::left << *(arr + j);
				for (long long i = 0; i < len1; ++i) std::cout << std::setw(4) << std::left << *(arr + i);
				break;
		}
		delete[] arr;
		arr = nullptr;
	}
	catch (const std::exception& error) {
		std::cerr << "Error: " << error.what() << "\n";
		return 1;
	}
	return 0;
}