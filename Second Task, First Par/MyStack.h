#pragma once
#include <iostream>

namespace My_Stack
{
	/* Наш элемент стека */
	struct stackElement
	{
		stackElement* previous_element;

		int data;
	};

	/*  Функция инициализации стека  */
	stackElement* init(int data);

	/* Функция добавления элемента в конец*/
	void add(stackElement*& previous_ptr, int data);

	/* Функция удаления последнего элемента */
	void remove_at(stackElement*& last_ptr);

	/*  Функция вывода элементов стека в консоль  */
	void show(stackElement* last_el);

	/*  Вспомогательная функция, для завершения работы  */
	void clean_memory(stackElement*& stack);

}