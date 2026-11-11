#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

long long sumdels(long long x) {
	std::vector <long long> dels;
	for (long long i = 1; i <= sqrt(x) + 1; ++i) {
		if (x % i == 0) {
			dels.push_back(i);
			dels.push_back(x / i);
		}
	}
	std::sort(dels.begin(), dels.end());
	dels.erase(std::unique(dels.begin(), dels.end()), dels.end());

	long long sum = 0;
	for (long long d : dels) {
		sum += d;
	}
	return sum;
}
int main() {
	try {
		long long num;
		std::cout << "Enter number (int.): ";
		if (!(std::cin >> num)) {
			throw std::runtime_error("Down!");
		}
		std::cout << "Sum of dels: " << sumdels(num) << "\n";
	}
	catch (const std::runtime_error& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	return 0;
}