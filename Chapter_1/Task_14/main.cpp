#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr std::string_view msg_input = "Enter number: \n";
	constexpr std::string_view msg_error = "User is down!!\n";
	constexpr std::string_view msg_elem = "Elements are: \n";
	constexpr std::string_view line_sep = "==============================\n";

	std::cout << msg_input << line_sep;

	long long n = 0;
	std::cin >> n;

	if (std::cin.fail() || n <= 0 || n > 1000000LL) {
		std::cout << msg_error << line_sep;
		return 1;
	}

	std::cout << msg_elem;

	for (long long i = 1; i <= n; ++i) {
		std::cout << (i << 1) << " ";
	}

	std::cout << "\n" << line_sep;
	std::cin.get();

	return 0;
}
