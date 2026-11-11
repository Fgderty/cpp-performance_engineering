#include <iostream>
#include <stdexcept>
#include <random>

int main() {
	try {
		long long size = 0;
		std::cout << "Enter kol-vo for 1-st and 2-nd arrays:";
		if (!(std::cin >> size)) throw std::runtime_error("Down!");

		long long *arr1 = new long long [size];
		long long *arr2 = new long long [size];

		std::random_device rd;
		std::mt19937_64 gen(rd());

		for (long long i = 0; i < size; ++i) {
			*(arr1 + i) = gen() % 10;
			*(arr2 + i) = gen() % 10;
		}

		std::cout << "Vector A: ";
		for (long long i = 0; i < size; ++i) {
			std::cout << *(arr1 + i) << " ";
		}

		std::cout << "Vector B: ";
		for (long long i = 0; i < size; ++i) {
			std::cout << *(arr2 + i) << " ";
		}

		std::cout << "\n";

		long long* ptr1 = arr1;
		long long* ptr2 = arr2;
		long long total_sum = 0;

		for (long long k = 0; k < size; ++k) {
			total_sum += (*ptr1) * (*ptr2);
			++ptr1;
			++ptr2;
		}

		std::cout << total_sum;
		delete[] arr1;
		delete[] arr2;

		arr1 = nullptr;
		arr2 = nullptr;

	}
	catch (std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	return 0;
}