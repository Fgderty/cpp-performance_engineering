#include <iostream>
#include <cmath>
#include <limits>

alignas(16) static constexpr char MSG_HEADER[48] = "Solution Ax = B\n";
alignas(16) static constexpr char MSG_INPUT_A[32] = "Enter A: ";
alignas(16) static constexpr char MSG_INPUT_B[32] = "Enter B: ";
alignas(16) static constexpr char MSG_ANY[32] = "x - any R-numbers\n";
alignas(16) static constexpr char MSG_NONE[32] = "Solutions none!\n";
alignas(16) static constexpr char MSG_RESULT[16] = "x = ";
alignas(16) static constexpr char MSG_ERROR[16] = "DOWN!\n";

static constexpr char NEW_LINE = '\n';

int main() noexcept{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << MSG_HEADER;

	double a = 0.0;
	double b = 0.0;

	std::cout << MSG_INPUT_A;
	std::cin >> a;
	if (std::cin.fail()) [[unlikely]] {
		std::cout << MSG_ERROR;
		return 1;
	}

	std::cout << MSG_INPUT_B;
	std::cin >> b;
	if (std::cin.fail()) [[unlikely]] {
		std::cout << MSG_ERROR;
		return 1;
	}

	const bool is_a_zero = std::abs(a) < std::numeric_limits <double> ::epsilon();
	const bool is_b_zero = std::abs(b) < std::numeric_limits <double> ::epsilon();

	if (is_a_zero) {
		if (is_b_zero) {
			std::cout << MSG_ANY;
		}
		else {
			std::cout << MSG_NONE;
		}
		return 0;
	}

	std::cout << MSG_RESULT << (b / a) << NEW_LINE;
	return 0;
}