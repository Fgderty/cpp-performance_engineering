#include <iostream>
#include <stdexcept>
#include <algorithm>

int main() {
	try {
		long long capacity = 8;
		long long length = 0;

		char* text = new char[capacity];

		std::cout << "Enter your text (any length): \n";

		char ch;

		while (std::cin.get(ch) && ch != '\n') {
			if (length + 1 >= capacity) {
				capacity *= 2;
				char* new_text = new char[capacity];

				for (long long i = 0; i < length; ++i) {
					*(new_text + i) = *(text + i);
				}

				delete[] text;
				text = new_text;
			}

			*(text + length) = ch;
			++length;
		}

		*(text + length) = '\0';

		char* left = text;
		char* right = text + length - 1;

		while (left < right) {
			char temp = *left;
			*left = *right;
			*right = temp;

			++left;
			--right;
		}

		std::cout << "Reversed text: \n" << text << "\n";

		delete[] text;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}