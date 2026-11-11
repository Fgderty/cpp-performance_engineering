#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>

int main() {
	try {
		long long num;
		std::cout << "Enter number in massive: ";
		if (!(std::cin >> num) || num <= 0) {
			throw std::runtime_error("Down!");
		}

		std::random_device rd;                                 //Инициализация источника системного шума
		std::mt19937_64 gen(rd());							//Генератор Вихрь Мерсенна(Крипторграфия надежнее рандома)
		std::uniform_int_distribution <long long> dis((std::numeric_limits<long long>::min)(),
													  (std::numeric_limits<long long>::max)());
		std::vector <long long> rand_num;
		rand_num.reserve(num);

		for (long long i = 0; i < num; ++i) {
			rand_num.push_back(dis(gen));

		}
		std::sort(rand_num.rbegin(), rand_num.rend());

		for (const long long& x : rand_num) {
			std::cout << x << "\n";
		}
	}
	
	catch (const std::exception& error) {
		std::cout << "Error: " << error.what() << "\n";
		return 1;
	}
	return 0;

}