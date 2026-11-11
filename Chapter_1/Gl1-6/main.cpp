#include <iostream>
#include <string_view>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	constexpr std::string_view msg_input = "Enter km (with use \".\"): \n";
	constexpr std::string_view user_error = "Users is down!\n";
	constexpr std::string_view msg_output = "Mile: ";
	constexpr std::string_view line_start = "==========\n";
	constexpr std::string_view line_end = "\n==========\n";

	constexpr double km_in_mile = 1.609344;

	std::cout << msg_input << line_start;


	double km = 0.0;
	std::cin >> km;

	if (std::cin.fail() || km < 0.0) {
		std::cout << user_error;
		return 1;
	}

	double mile = km / km_in_mile;

	std::cout << msg_output << mile << line_end;
	std::cin.get();

	return 0;

}