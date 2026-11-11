#include <iostream>
#include <cmath>
#include <stdexcept>

int main() {
	double a, b, c, x1, x2;
	try {

		std::cout << "Solution a^2*x + b*x + c = 0" << "\n";
		std::cout << "Enter a: " << "\n";
		if (!(std::cin >> a)) throw std::runtime_error("Down!");
		std::cout << "Enter b: " << "\n";
		if (!(std::cin >> b)) throw std::runtime_error("Down!");
		std::cout << "Enter c: " << "\n";
		if (!(std::cin >> c)) throw std::runtime_error("Down!");

		std::cout << "\n";
		if (a == 0) {
			if (b == 0 && c == 0) throw std::runtime_error("x - any R-numbers");
			if (b == 0 && c == 0) throw std::runtime_error("Solutions none");
			if (b != 0) {
				x1 = -(c / b);
				std::cout << "x1 = x2 =  " << x1 << "\n";
			}
			else {
				throw std::runtime_error("Solutions none");
			}
		}
		else {
			x1 = (-b + sqrt(b * b - 4 * a * c)) / 2 * a;
			x2 = (-b - sqrt(b * b - 4 * a * c)) / 2 * a;
			std::cout << "x1 = " << x1 << "\t";
			std::cout << "x2 = " << x2 << "\n";
		}
	}
	catch (const std::runtime_error& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	return 0;
}