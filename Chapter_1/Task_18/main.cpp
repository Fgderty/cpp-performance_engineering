#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr std::string_view msg_input = "Enter number: \n";
	constexpr std::string_view msg_error = "User is down!!\n";
	constexpr std::string_view line_sep  = "==============================\n";
	constexpr std::string_view space	 = " ";

	std::cout << msg_input << line_sep;

	long long n = 0;
	std::cin >> n;

	n <<= 1;

	if (std::cin.fail() || n <= 0 || n > 4000000000LL) {
		std::cout << msg_error << line_sep;
		return 1;
	}

	long long f1 = 1;
	long long f2 = 1;
	long long next;

	for (; f2 <= n; ) {
		std::cout << f1 << space;
		next = f1 + f2;
		f1 = f2;
		f2 = next;
	}

	std::cout << "\n" << line_sep;
	std::cin.get();

	return 0;
}
