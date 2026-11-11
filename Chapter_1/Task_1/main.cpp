#include<iostream>
#include <string_view>

int main() {
	//Отключение синхронизации тяжелых СИ потоков
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(nullptr);

	//Упакование декоративных линий в ультра_скоростные  строковые представления
	//Не происходит выделение лишней памяти
	alignas(16) constexpr char line_start[32] = "====================\n";
	alignas(16) constexpr char line_end[32] = "\n====================\n";

	//Развертывание строки
	//Процессор не выполняет циклы в рантайме, а загружаются готовые данные
	constexpr std::string_view payload = "1 2 3 4 5 6 7 8 9 10";

	//Вывод всего одним системным вызовом
	std::cout << line_start << payload << line_end;
	std::cin.get();

	return 0;
}
