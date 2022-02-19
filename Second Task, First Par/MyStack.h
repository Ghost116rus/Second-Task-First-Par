#pragma once
#include <iostream>

namespace My_Stack
{
	/* ��� ������� ����� */
	struct stackElement
	{
		stackElement* previous_element;

		int data;
	};

	/*  ������� ������������� �����  */
	stackElement* init(int data);

	/* ������� ���������� �������� � �����*/
	void add(stackElement*& previous_ptr, int data);

	/* ������� �������� ���������� �������� */
	void remove_at(stackElement*& last_ptr);

	/*  ������� ������ ��������� ����� � �������  */
	void show(stackElement* last_el);

	/*  ��������������� �������, ��� ���������� ������  */
	void clean_memory(stackElement*& stack);

}