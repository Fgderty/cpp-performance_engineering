#include <iostream>
#include <stdexcept>
#include <random>
#include <iomanip>

int main() {
    try {
        long long len1 = 0, len2 = 0;
        std::cout << "Enter length of 1-st Array: ";
        if (!(std::cin >> len1) || len1 <= 0) throw std::runtime_error("Invalid length for first array!");
        std::cout << "Enter length of 2-nd Array: ";
        if (!(std::cin >> len2) || len2 <= 0) throw std::runtime_error("Invalid length for second array!");

        std::cout << "Enter comparison type (\"<\" for min, \">\" for max): ";
        char ch;
        if (!(std::cin >> ch) || (ch != '<' && ch != '>')) throw std::runtime_error("Invalid comparison type!");

        long long maxLen = (len1 > len2) ? len1 : len2;
        long long minLen = (len1 < len2) ? len1 : len2;
        long long len3 = (ch == '<') ? minLen : maxLen;
        long long* sum_arrays = new long long[len1 + len2 + len3];

        std::random_device rd;
        std::mt19937_64 gen(rd());

        std::cout << "\n1-st Array:\n";
        for (long long i = 0; i < len1; ++i) {
            *(sum_arrays + i) = static_cast<long long>(gen() % 100);
            std::cout << std::setw(4) << std::left << *(sum_arrays + i);
        }
        std::cout << "\n2-nd Array:\n";
        for (long long i = 0; i < len2; ++i) {
            *(sum_arrays + len1 + i) = static_cast<long long>(gen() % 100);
            std::cout << std::setw(4) << std::left << *(sum_arrays + len1 + i);
        }

        for (long long i = 0; i < minLen; ++i) {

            long long val1 = *(sum_arrays + i);
            long long val2 = *(sum_arrays + len1 + i);


            if (ch == '<') {
                *(sum_arrays + len1 + len2 + i) = (val1 < val2) ? val1 : val2;
            }
            else {
                *(sum_arrays + len1 + len2 + i) = (val1 > val2) ? val1 : val2;
            }
        }

        if (ch == '>') {
            if (len1 > len2) {
                for (long long i = minLen; i < len1; ++i) {
                    *(sum_arrays + len1 + len2 + i) = *(sum_arrays + i);
                }
            }else if (len2 > len1) {
                for (long long i = minLen; i < len2; ++i) {
                    *(sum_arrays + len1 + len2 + i) = *(sum_arrays + len1 + i);
                }
            }
        }

        std::cout << "\n3-rd Array:\n";
        for (long long i = 0; i < len3; ++i) {
            std::cout << std::setw(4) << std::left << *(sum_arrays + len1 + len2 + i);
        }

        std::cout << "\n";

        delete[] sum_arrays;
        sum_arrays = nullptr;
    }
    catch (const std::exception& error) {
        std::cerr << "Error: " << error.what() << "\n";
        return 1;
    }
    return 0;
}