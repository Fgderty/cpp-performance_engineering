#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	alignas(16) constexpr std::string_view line_start = "=========\n";
	alignas(16) constexpr std::string_view line_end = "\n=========\n";

	alignas(16) constexpr std::string_view payload = "1 3 5 7 9";

	std::cout << line_start << payload << line_end;
	std::cin.get();

	return 0;
}