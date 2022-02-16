// Second Task, First Par.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include "MyStack.h"
#include "user_interface.h"





int main()
{
	setlocale(LC_ALL, "ru");


	My_Stack::stackElement* my_stack;

	menu(my_stack);

	My_Stack::clean_memory(my_stack);
}

