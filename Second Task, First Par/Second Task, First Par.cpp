// Second Task, First Par.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>



struct stackElement
{
	stackElement* previous_element;
	
	// data my_data;
	int data;
};


stackElement* init(int data)
{
	stackElement* temp = new stackElement;
	temp->previous_element = NULL;
	temp->data = name;


	return temp;
}

void add(stackElement*& previous_ptr, int data)
{
	stackElement* last_element = new stackElement();

	last_element->previous_element = previous_ptr;

	

	previous_ptr = last_element;
}



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
		std::cout << number++ << "-й элемент стека с конца\t" << "Данные: " << last_el->data << std::endl;
		last_el = last_el->previous_element;
	}
}


int main()
{
	setlocale(LC_ALL, "ru");


	stackElement* my_stack = init("Калеев Д.А");
	add(my_stack, "Гайфуллин ДАмир ")
	show(my_stack);
	remove_at(my_stack);


}

