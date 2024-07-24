#include <iostream>
#include "List.hpp"

int main() {
	setlocale(LC_ALL, "Russian");


	List<int> list1;
	list1.push_back(15);
	list1.push_back(7);
	list1.push_front(42);
	//list1.clear();
	list1.print();// выводит в обратном порядке
	//list1.reverse_print();//выводит в исходном порядке
	list1.pop_front();
	list1.print();

	List<std::string> list2{ "Hello", "World", "Apples" };
	list2.print();



	return 0;
}