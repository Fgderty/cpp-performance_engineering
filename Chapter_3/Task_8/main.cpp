#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <random>
#include <limits>

int main() {
	try {
		long long size = 0;
		std::cout << "Enter amount of array: ";
		if (!(std::cin >> size) || size <= 0) throw std::runtime_error("Down!");

		long long* array = new long long[size];
		std::random_device rd;
		std::mt19937_64 gen(rd());
		//std::uniform_int_distribution <long long> dis((std::numeric_limits <long long> ::min)(), (std::numeric_limits <long long> ::max)());

		for (long long i = 0; i < size; ++i) *(array + i) = gen() % 10;

		long long stride = 0;
		std::cout << "\nEnter number for stride: ";

		if(!(std::cin >> stride)) throw std::runtime_error("Down!");

		long long real_stride = stride % size;

		std::cout << "\nArray: ";

		for (long long i = 0; i < size; ++i) std::cout << *(array + i) << " ";

		std::cout << "\nArray with stride = " << stride << "\n";

		for (long long i = 0; i < size; ++i) std::cout << *(array + ((i - real_stride + size) % size)) << " ";

		delete[] array;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}