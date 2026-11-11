#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr std::string_view msg_input  = "Enter number: \n";
	constexpr std::string_view line_start = "==============================\n";
	constexpr std::string_view user_error = "User is down!!\n";
	constexpr std::string_view line_end   = "==============================\n";

	std::cout << msg_input << line_start;

	long long n = 0;
	std::cin >> n;

	if (std::cin.fail() || n <= 0 || n > 3000000000LL) {
		std::cout << user_error << line_end;
		return 1;
	}

	long long sum = (1 + n) * n >> 1;

	std::cout << sum << "\n" << line_end;
	std::cin.get();

	return 0;
}
