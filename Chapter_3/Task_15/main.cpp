#include <iostream>
#include <stdexcept>

int main() {
	try {
		long long capacity = 10;
		char *text = new char[capacity]();
		long long length = 0;

		std::cout << "Enter text (any size): ";
		char ch;

		while (std::cin.get(ch) && ch != '\n') {
			if (ch == '\n' || ch == '\r') break;
			if (length >= capacity - 1) {
				long long newCapacity = capacity * 2;
				char* newText = new char[newCapacity]();

				for (long long i = 0; i < length; ++i) {
					newText[i] = text[i];
				}

				delete[] text;
				text = newText;
				capacity = newCapacity;
			}

			text[length] = ch;
			++length;
		}
		text[length] = '\0';

		long long wordCount = 0;
		long long currentLength = 0;
		bool inWord = false;

		for (long long i = 0; text[i] != '\0'; ++i) {
			char currentChar = text[i];

			if (currentChar == ' ') {
				if (inWord) {
					std::cout << "Word [" << wordCount << "] -> Length: " << currentLength << " chars.\n";
					currentLength = 0;
					inWord = false;
				}
			}
			else {
				if (!inWord) {
					++wordCount;
					inWord = true;
				}
				++currentLength;
			}
		}

		if (inWord && currentLength > 0) {
			std::cout << "Word [" << wordCount << "] -> Length: " << currentLength << " chars.\n";
		}

		delete[] text;
	}
	catch (const std::exception& error) {
		std::cout << error.what() << "\n";
		return 1;
	}
	std::cout << "\n";
	return 0;
}