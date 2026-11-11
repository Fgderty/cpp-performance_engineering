#include <iostream>

int main() {
	try {
		long long num;
		std::cout << "Enter num 1 - 10: ";
		if (!(std::cin >> num) || num < 1 || num > 10) {
			throw std::runtime_error("Down!");
		}
		switch (num) {
			case 1:
				std::cout << num << " is number of Fibonachi";
				break;
			case 2:
				std::cout << num << " is number of Fibonachi";
				break;
			case 3:
				std::cout << num << " is number of Fibonachi";
				break;
			case 5:
				std::cout << num << " is number of Fibonachi";
				break;
			case 8:
				std::cout << num << " is number of Fibonachi";
				break;
			default:
				std::cout << num << " is not number of Fibonachi";;
		}
	}
	catch (const std::runtime_error& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	return 0;
 }