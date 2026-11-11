#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr std::string_view msg_input  = "Enter count of numbers: \n";
	constexpr std::string_view line_start = "=========\n";
	constexpr std::string_view line_end	  = "\n=========\n";
	constexpr std::string_view space	  = " ";

	std::cout << msg_input << line_start;

	long long n = 0;
	std::cin >> n;

	if (std::cin.fail() || n <= 0) {
		return 1;
	}

	long long f1 = 1;
	long long f2 = 1;
	long long next_val = 0;

	for(long long i = 0; i < n; ++i){
		std::cout << f1 << space;

		next_val = f1 + f2;
		f1 = f2;
		f2 = next_val;
	}

	std::cout << line_end;
	std::cin.get();

	return 0;
}