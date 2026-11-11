#include <iostream>
#include <cmath>
#include <vector>>
#include <algorithm>

int main() {
	long long num1, num2, length = 0;

	std::vector < long long > dels1;
	std::vector < long long > dels2;
	std::vector < long long > dels;

	std::cout << "Enter 1-st number: ";
	if (std::cin >> num1) {

		std::cout << "Enter 2-nd number: ";
		if (std::cin >> num2) {

			for (long long i = 1; i <= sqrt(num1) + 1; i++) {
				if (num1 % i == 0) {
					dels1.push_back(i);
					dels1.push_back(num1 / i);
				}
			}
			std::sort(dels1.begin(), dels1.end());

			for (long long j = 1; j <= sqrt(num2) + 1; j++) {
				if (num2 % j == 0) {
					dels2.push_back(j);
					dels2.push_back(num2 / j);
				}
			}
			std::sort(dels2.begin(), dels2.end());

			dels1.erase(std::unique(dels1.begin(), dels1.end()), dels1.end());
			dels2.erase(std::unique(dels2.begin(), dels2.end()), dels2.end());

			std::cout << "\n";

			std::cout << "Dels num1: ";
			for (long long& x : dels1) {
				std::cout << x << " ";
			}
			std::cout << "\n";

			std::cout << "Dels num2: ";
			for (long long& x : dels2) {
				std::cout << x << " ";
			}
			std::cout << "\n";

			for (long long& x : dels2) {
				dels1.push_back(x);
			}

			std::sort(dels1.begin(), dels1.end());
			std::unique(dels1.begin(), dels1.end());

			for (long long& x : dels1) {
				if (num1 % x == 0 && num2 % x == 0) {
					dels.push_back(x);
				}
			}

			for (long long& x : dels) {
				length++;
			}

			std::cout << "\n";
			std::cout << "MuD: " << dels[length - 1];
		}
	}
	return 0;
}