#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr std::string_view msg_input = "Enter number: \n";
	constexpr std::string_view msg_error = "User is down!!\n";
	constexpr std::string_view line_sep  = "==============================\n";

	std::cout << msg_input << line_sep;

	long long n = 0;
	std::cin >> n;

	if (std::cin.fail() || n <= 0 || (n % 2 == 0) || n > 3000000000LL) {
		std::cout << msg_error << line_sep;
		return 1;
	}

	long long sum = ((1 + n) * (1 + n)) >> 2;

	std::cout << sum << "\n" << line_sep;
	std::cin.get();

	return 0;
}
