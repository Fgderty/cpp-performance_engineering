#include <iostream>

class alignas(32) PythagoreanChecker {
private:
	long long a_ = 0;
	long long b_ = 0;
	long long c_ = 0;

public:
	constexpr PythagoreanChecker() noexcept = default;

	[[nodiscard]] bool read_sides() noexcept {
		alignas(16) static constexpr char MSG_A[16] = "Enter a: ";
		alignas(16) static constexpr char MSG_B[16] = "Enter b: ";
		alignas(16) static constexpr char MSG_C[16] = "Enter c: ";
		alignas(16) static constexpr char MSG_INVALID[32] = "Invalid input DATA!\n";

		std::cout << MSG_A;
		std::cin >> a_;
		if (std::cin.fail()) [[unlikely]] {
			std::cout << MSG_INVALID;
			std::cin.clear(); 
			return false;
		}

		std::cout << MSG_B;
		std::cin >> b_;
		if (std::cin.fail()) [[unlikely]] {
			std::cout << MSG_INVALID;
			std::cin.clear();
			return false;
		}

		std::cout << MSG_C;
		std::cin >> c_;
		if (std::cin.fail()) [[unlikely]] {
			std::cout << MSG_INVALID;
			std::cin.clear();
			return false;
		}

		return true;
	}

	[[nodiscard]] constexpr bool is_right_triangle() const noexcept {
		return (a_ * a_ + b_ * b_) == (c_ * c_);
	}

	void print_error_details() const noexcept {
		alignas(16) static constexpr char MSG_SEP[16] = ", ";
		alignas(32) static constexpr char MSG_ERROR[32] = " are not equal a^2 + b^2 = c^2";

		std::cout << a_ << MSG_SEP << b_ << MSG_SEP << c_ << MSG_ERROR << '\n';
	}
};

int main() noexcept {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	alignas(32) static constexpr char MSG_TRUE[32] = "It is a right triangle.\n";

	PythagoreanChecker checker;

	if (!checker.read_sides()) [[unlikely]] {
		std::cin.get();
		return 1;
	}

	if (checker.is_right_triangle()) {
		std::cout << MSG_TRUE;
	}
	else {
		checker.print_error_details();
	}

	std::cin.get();
	return 0;
}