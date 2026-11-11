#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <stdexcept>
#include <random>

int main() {
	try {
		long long num;
		std::cout << "Enter number (int.): ";
		if (!(std::cin >> num) || num <= 0) throw std::runtime_error("Down!");

		std::vector <long long> rand_nums;
		rand_nums.reserve(num);

		std::random_device rd;
		std::mt19937_64 gen(rd());
		std::uniform_int_distribution <long long> dis((std::numeric_limits <long long> ::min)(),
													  (std::numeric_limits <long long> ::max)());
		for (long long i = 0; i < num; ++i) {
			rand_nums.push_back(gen());
		}

		for (long long& x : rand_nums) std::cout << x << " ";

		long long left = 0;
		long long right = rand_nums.size() - 1;

		while (left < right) {											//Инвертирование массива
			std::swap(rand_nums[left], rand_nums[right]);
			++left;
			--right;
		}

		std::cout << "\n";
		std::cout << "\n";

		for (long long& x : rand_nums) std::cout << x << " ";
	}
	catch(const std::exception& error){
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}