#include <iostream>
#include <cmath>
#include <cstdlib>

alignas(16) static constexpr char MSG_INPUT_X[80] = "Enter x for ln(1 + x) using DOT (e.g. 0.5), x must be in (-1, 1): \n";
alignas(16) static constexpr char MSG_ERROR[64] = "Error: Invalid input or x is out of range (-1, 1)\n";
alignas(16) static constexpr char MSG_RESULT[32] = "Calculated ln(1 + x) = ";
alignas(16) static constexpr char MSG_EXPECTED[32] = "Standard std::log = ";
alignas(16) static constexpr char LINE_SEP[16] = "==============\n";

static constexpr char NEW_LINE = '\n';

static constexpr size_t ITERATIONS_COUNT = 7;

int main() noexcept {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << MSG_INPUT_X << LINE_SEP;
	double x = 0.0;
	std::cin >> x;

	if (std::cin.fail() || x <= -1.0 || x >= 1.0) [[unlikely]] {
		std::cout << MSG_ERROR << LINE_SEP;
		return 1;
	}

	double sum = 0.0;
	double current_pow = x;
	double sign = 1.0;

	for (long long n = 1; n <= ITERATIONS_COUNT; ++n) {
		sum += sign * (current_pow / static_cast <double> (n));
		current_pow *= x;
		sign = -sign;
	}

	std::cout << MSG_RESULT << sum << NEW_LINE;
	std::cout << MSG_EXPECTED << std::log(1.0 + x) << NEW_LINE;
	std::cout << LINE_SEP;

	std::cin.get();

	return 0;
}