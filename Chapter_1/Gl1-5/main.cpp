#include <iostream>
#include <cstdlib>
#include <new>
#include <memory>

alignas(16) static constexpr char MSG_INPUT[48]	  = "Enter n (n must be in (0, 61)): \n";
alignas(16) static constexpr char USERS_ERROR[32] = "Users is Down!\n";
alignas(16) static constexpr char LINE_SEP[16]	  = "==========\n";

static constexpr char SPACE						  = ' ';
static constexpr char NEW_LINE					  = '\n';

int main() noexcept{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cout << MSG_INPUT << LINE_SEP;

	long long n = 0;
	std::cin >> n;

	if (std::cin.fail() || n <= 0 || n > 61) [[unlikely]]{
		std::cout << USERS_ERROR;
		return 1;
	}

	const size_t elements_count = static_cast <size_t> (n + 1);
	const size_t element_bytes = elements_count * sizeof(long long);
	constexpr size_t CACHE_LINE = 64;
	
	const size_t total_buffer_bytes = element_bytes * CACHE_LINE;

	void* const raw_memory = std::malloc(total_buffer_bytes);
	if (!raw_memory) [[unlikely]] {
		std::free(raw_memory);
		return 1;
	}

	void* ptr_to_align = raw_memory;
	size_t space_left = total_buffer_bytes;

	void* aligned_ptr = std::align(CACHE_LINE, element_bytes, ptr_to_align, space_left);
	if (!aligned_ptr) [[unlikely]] {
		std::free(raw_memory);
		return 1;
	}

	long long* __restrict const typed_ptr = static_cast <long long*> (aligned_ptr);
	long long* __restrict const row = std::assume_aligned <CACHE_LINE> (typed_ptr);

	*(row + 0) = 1;
	long long current_val = 1;

	for (long long k = 1; k <= n; ++k) {
		current_val = current_val * (n - k + 1) / k;
		*(row + k) = current_val;
	}

	for (long long k = 0; k <= n; ++k) {
		std::cout << *(row + k) << SPACE;
	}
	
	std::cout << NEW_LINE << LINE_SEP;
	std::cin.get();

	std::free(raw_memory);

	return 0;
}