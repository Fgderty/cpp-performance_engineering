#include <iostream>
#include <cmath>
#include <string_view>

alignas(16) static constexpr char msg_input[16]  = "Enter number:\n";
alignas(16) static constexpr char msg_error[16]  = "User is down!\n";
alignas(16) static constexpr char line_sep[32]   = "==============================\n";
alignas(16) static constexpr char msg_output[16] = "Dels of number\n";
static constexpr std::string_view space         = " ";

int main() noexcept{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << msg_input << line_sep;

	long long num;
	std::cin >> num;

	if (std::cin.fail() || num == 0 || num > 3000000000LL)[[unlikely]] {
		std::cout << msg_error << line_sep;
		return 1;
	}

	num = std::abs(num);

	long long sqrt_num = static_cast <long long> (std::sqrt(num));
	size_t size = (sqrt_num + 1) << 1;
	long long* array = new long long[size] {0};
	size_t left = 0;
	size_t right = size - 1;

	for (size_t i = 1; i <= sqrt_num; ++i) [[likely]]{
		if (num % i == 0) {
			*(array + ++left) = i;
			*(array + --right) = num / i;
		}
	}

	std::cout << msg_output;
	for (size_t i = 1; i <= left; ++i) {
		std::cout << *(array + i) << space;
	}

	for (size_t i = right; i < size - 1; ++i) {
		std::cout << *(array + i) << space;
	}
	std::cout << "\n" << line_sep;

	delete[] array;
	array = nullptr;

	return 0;
}	