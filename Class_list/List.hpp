#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <iostream>
#include <exception>
#include <initializer_list>

template <typename ANY>
class List {

private:
	struct Item {
		ANY value = ANY();// вызов коструктора по умолчанию, для любых значений
		Item* next = nullptr;
		Item* prev = nullptr;
		Item(ANY value) : value(value) {}
	};
	Item* first;
	Item* last;
	size_t length; 
	void set_defaults();
public:
	List();
	List(const std::initializer_list<ANY>& inits);
	~List();

	void print() const;
	void reverse_print() const;
	//базовый список 
	void push_back(ANY value);
	void push_front(ANY value);
	void pop_back();
	void pop_front();
	void clear();

	size_t size() const;
	ANY& front();
	ANY& front() const;
	ANY& back();
	ANY& back() const; 
};



template<typename ANY>
inline void List<ANY>::set_defaults() {
	first = nullptr;
	last = nullptr;
	length = 0;
}

template<typename ANY>
List<ANY>::List() { set_defaults(); }

template<typename ANY>
List<ANY>::List(const std::initializer_list<ANY>& inits) {
	set_defaults();
	for (auto el : inits)
		push_back(el);
}



template<typename ANY>
List<ANY>::~List() { clear(); }

template<typename ANY>
void List<ANY>::print() const {
	if (first == nullptr) {
		std::cout << '\n';
		return;
	}
	Item* current = first;//указатель на текущий элемент
	do {
		std::cout << current->value << ' ';
		current = current->next;//перенаправление на следующий элемент
	} while (current != nullptr);
	std::cout << std::endl;
}

template<typename ANY>
void List<ANY>::reverse_print() const {
	if (last == nullptr) {
		std::cout << '\n';
		return;
	}
	Item* current = last;
	do {
		std::cout << current->value << ' ';
		current = current->prev;
	} while (current != nullptr);
	std::cout << std::endl;
}

template<typename ANY>
void List<ANY>::push_back(ANY value) {
	if (last == nullptr) {
		last = first = new Item(value);
		++length;
		return;
	}
	last->next = new Item(value);
	last->next->prev = last;
	last = last->next;
	++length;
}

template<typename ANY>
void List<ANY>::push_front(ANY value) {
	if (first == nullptr) {
		first = last = new Item(value);
		++length;
		return;
	}
	first->prev = new Item(value);
	first->prev->next = first;
	first = first->prev;
	++length;
}

template<typename ANY>
void List<ANY>::pop_back() {//удаление с конца списка
	if (last == nullptr)
		throw std::exception("list have no elements");

	if (first == last) {
		delete last;
		set_defaults();
		return;
	}

	last = last->prev;//перенаправление на препоследний элемент
	delete last->next; //удаляем последний элемент
	last->next = nullptr;//присваеваем значение 0
	--length;//уменьшаем размер массива на 1
}

template<typename ANY>
 void List<ANY>::pop_front() {//удаление с начала списка
	 if (first == nullptr)
		 throw std::exception("list have no elements");

	 if (first == last) {
		 delete first;
		 set_defaults();
		 return;
	 }
	 //меняем last на first
	 first = first->next; 
	 delete first->prev; 
	 first->prev = nullptr;
	 --length;
}

 template<typename ANY>
void List<ANY>::clear() {
	if (first == nullptr)
		return;// если равен 0 то все останавливется, цикл не запускается

	Item* current = first;
	do {
		Item* to_delete = current;
		current = current->next;
		delete to_delete;
	} while (current != nullptr);
	set_defaults();
}

template<typename ANY>
size_t List<ANY>::size() const {
	return length;
}

template<typename ANY>
ANY& List<ANY>::front() {
	return first->value;
}
template<typename ANY>
ANY& List<ANY>::front() const {
	return first->value;
}

template<typename ANY>
ANY& List<ANY>::back() {
	return last->value;
}
template<typename ANY>
ANY& List<ANY>::back() const {
	return last->value;
}



#endif // _LIST_HPP_