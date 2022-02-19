#include "MyStack.h"


using namespace My_Stack;

stackElement* My_Stack::init(int data)
{
	stackElement* temp = new stackElement;		// Выделяем память для элемента стека
	temp->previous_element = NULL;				// т.к это самый первый элемент, то за ним никого нет
	temp->data = data;							// заносим данные

	return temp;								// возвращаем указатель
}


void My_Stack::add(stackElement*& previous_ptr, int data)
{
	//if (!(previous_ptr))						// на случай, если стек не инициализрован
	//{
	//	std::cout << "Стек не инициализирован, воспользуйтесь функцией init\n";
	//	return;
	//}


	stackElement* last_element = new stackElement();	// создаем новый элемент

	last_element->previous_element = previous_ptr;		// В новый элемент заносим указатель на предыдущий элемент стека
	last_element->data = data;							// Заносим данные


	previous_ptr = last_element;						// Мы получали указатель на предыдущий элемент, сейчас делаем так, чтобы он указывал на последний элемент
}

void My_Stack::remove_at(stackElement*& last_ptr)
{
	if (last_ptr)
	{
		stackElement* previous_element = last_ptr->previous_element;

		delete last_ptr;

		last_ptr = previous_element;
		
		std::cout << "Удаление выполнено успешно\n";
	}
	else
	{
		std::cout << "Невозможно выполнить операцию, т.к стек не инициализирован\n";
	}
}


void My_Stack::show(stackElement* last_el)
{
	int number = 1;

	while (last_el)
	{
		std::cout << number++ << "-й элемент стека\t" << "Данные: " << last_el->data << std::endl;
		last_el = last_el->previous_element;
	}
}

void My_Stack::clean_memory(stackElement*& stack)
{
	while (stack)
	{
		stackElement* previous_element = stack->previous_element;
		delete stack;
		stack = previous_element;
	}
}

