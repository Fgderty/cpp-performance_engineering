#include <iostream>
#include <string_view>
//#include <string>
//#include <sstream>

static constexpr char msg_input[32]     = "Enter number (letter to exit):\n";
static constexpr char msg_output[16]    = "You entered:\n";
static constexpr char msg_error[24]     = "No numbers entered!\n";
static constexpr char line_sep[32]      = "==============================\n";
static constexpr std::string_view space = " ";

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << msg_input << line_sep;

	//std::string line;
	//std::getline(std::cin, line);

	//std::stringstream ss(line);
	long long n;
	bool s_num = false;

	while (/*ss >> n*/ std::cin >> n) {
		if (!s_num) {
			std::cout << msg_output;
			s_num = true;
		}
		std::cout << n << space;
	}

	if (!s_num) {
		std::cout << msg_error << line_sep;
		return 1;
	}

	std::cout << "\n" << line_sep;
	std::cin.get();

	return 0;
}