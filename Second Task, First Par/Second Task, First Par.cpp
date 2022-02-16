// Second Task, First Par.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include "MyStack.h"



int main()
{
	setlocale(LC_ALL, "ru");


	My_Stack::stackElement* my_stack = My_Stack::init(7);
	My_Stack::add(my_stack, 28);
	My_Stack::show(my_stack);
	My_Stack::remove_at(my_stack);



	My_Stack::clean_memory(my_stack);
}

