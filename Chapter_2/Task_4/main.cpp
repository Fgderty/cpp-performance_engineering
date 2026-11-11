#include <iostream>
#include <stdexcept>
#include <cmath>
#include <string_view>

alignas(16) static constexpr char MSG_INPUT1[24] = "Enter 1-st number:\n";
alignas(16) static constexpr char MSG_INPUT2[24] = "Enter 2-nd number:\n";
alignas(16) static constexpr char MSG_ERROR[16] = "Invalid number\n";
alignas(16) static constexpr char LINE_SEP[32] = "==============================\n";
alignas(16) static constexpr char MSG_RESULT[24] = "Result: numbers ";
alignas(16) static constexpr char MSG_COPR[32] = " are COPRIME\n";
alignas(16) static constexpr char MSG_GCD1[8] = "GCD: 1\n";
alignas(16) static constexpr char MSG_RESULTGCD[24] = "Result: GCD for ";
alignas(16) static constexpr std::string_view MSG_IS = " is ";
alignas(16) static constexpr std::string_view MSG_AND = " and ";

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long num1 = 0;
	long long num2 = 0;

	std::cout << MSG_INPUT1 << LINE_SEP;
	std::cin >> num1;

	if (std::cin.fail() || num1 > 3000000000LL) {
		std::cout << MSG_ERROR << LINE_SEP;
		return 1;
	}

	std::cout << MSG_INPUT2 << LINE_SEP;
	std::cin >> num2;

	if (std::cin.fail() || num2 > 3000000000LL) {
		std::cout << MSG_ERROR << LINE_SEP;
		return 1;
	}

	long long a = std::abs(num1);
	long long b = std::abs(num2);

	if (a == 0 || b == 0) {
		std::cout << MSG_ERROR << LINE_SEP;
		return 1;
	}

	while (b != 0) {
		long long temp = b;
		b = a % b;
		a = temp;
	}
	

	if (a == 1 || b == 1) {
		std::cout << MSG_RESULT << num1 << MSG_AND << num2 << MSG_COPR;
		std::cout << MSG_GCD1 << LINE_SEP;

	}
	else {
		std::cout << MSG_RESULTGCD << num1 << MSG_AND << num2 << MSG_IS << a << "\n";
		std::cout << LINE_SEP;
	}

	return 0;
}