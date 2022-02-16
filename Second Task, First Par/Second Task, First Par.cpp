// Second Task, First Par.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>



struct stackElement
{
	stackElement* previous_element;
	
	int data;
};

/*  Функция инициализации стека  */
stackElement* init(int data)
{
	stackElement* temp = new stackElement;
	temp->previous_element = NULL;
	temp->data = data;


	return temp;
}

/* Функция добавления элемента в конец*/
void add(stackElement*& previous_ptr, int data)
{
	if (!(previous_ptr))
	{
		std::cout << "Стек не инициализирован, воспользуйтесь функцией init\n";
		return;
	}


	stackElement* last_element = new stackElement();

	last_element->previous_element = previous_ptr;
	last_element->data = data;
	

	previous_ptr = last_element;
}


/* Функция удаления последнего элемента */
void remove_at(stackElement*& last_ptr)
{
	if (!(last_ptr->previous_element))
	{
		delete last_ptr; last_ptr = nullptr;

		return;
	}
	
	stackElement* previous_element = last_ptr->previous_element;
	
	delete last_ptr;

	last_ptr = previous_element;
}

void show(stackElement* last_el)
{
	int number = 1;

	while (last_el)
	{
		std::cout << number++ << "-й элемент стека\t" << "Данные: " << last_el->data << std::endl;
		last_el = last_el->previous_element;
	}
}



void clean_memory(stackElement*& stack)
{
	while (stack)
	{
		stackElement* previous_element = stack->previous_element;
		delete stack;
		stack = previous_element;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");


	stackElement* my_stack = init(7);
	add(my_stack, 28);
	show(my_stack);
	remove_at(my_stack);




	clean_memory(my_stack);
}

