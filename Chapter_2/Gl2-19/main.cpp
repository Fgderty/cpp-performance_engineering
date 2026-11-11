#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>

int main() {
	try {
		long long num;
		std::cout << "Enter number(int.): ";
		if (!(std::cin >> num) || num <= 0) throw std::runtime_error("Down!");
		std::vector <long long> vect_rand;
		std::vector <long long> vect1;
		std::vector <long long> vect2;
		vect_rand.reserve(num);

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution <long long> dis(std::numeric_limits <long long> ::min(),
			std::numeric_limits <long long> ::max());
		for (long long i = 0; i < num; ++i) vect_rand.push_back(gen());

		std::cout << "\n";

		for (long long& x : vect_rand) std::cout << x << " ";

		std::cout << "\n";

		for (long long& x : vect_rand) {
			if (x % 2 == 1) vect1.push_back(x);
			if (x % 2 == 0) vect2.push_back(x);
		}
		std::sort(vect1.begin(), vect1.end());
		std::sort(vect2.rbegin(), vect2.rend());

		vect_rand.clear();

		for (long long& x : vect1) vect2.push_back(x);

		for (long long& x : vect2) std::cout << x << " ";
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	return 0;

}