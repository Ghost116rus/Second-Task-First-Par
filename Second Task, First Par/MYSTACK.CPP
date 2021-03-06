#include "MyStack.h"


using namespace My_Stack;

stackElement* My_Stack::init(int data)
{
	stackElement* temp = new stackElement;		// �������� ������ ��� �������� �����
	temp->previous_element = NULL;				// �.� ��� ����� ������ �������, �� �� ��� ������ ���
	temp->data = data;							// ������� ������

	return temp;								// ���������� ���������
}


void My_Stack::add(stackElement*& previous_ptr, int data)
{
	//if (!(previous_ptr))						// �� ������, ���� ���� �� ��������������
	//{
	//	std::cout << "���� �� ���������������, �������������� �������� init\n";
	//	return;
	//}


	stackElement* last_element = new stackElement();	// ������� ����� �������

	last_element->previous_element = previous_ptr;		// � ����� ������� ������� ��������� �� ���������� ������� �����
	last_element->data = data;							// ������� ������


	previous_ptr = last_element;						// �� �������� ��������� �� ���������� �������, ������ ������ ���, ����� �� �������� �� ��������� �������
}

void My_Stack::remove_at(stackElement*& last_ptr)
{
	if (last_ptr)
	{
		stackElement* previous_element = last_ptr->previous_element;

		delete last_ptr;

		last_ptr = previous_element;
		
		std::cout << "�������� ��������� �������\n";
	}
	else
	{
		std::cout << "���������� ��������� ��������, �.� ���� �� ���������������\n";
	}
}


void My_Stack::show(stackElement* last_el)
{
	int number = 1;

	while (last_el)
	{
		std::cout << number++ << "-� ������� �����\t" << "������: " << last_el->data << std::endl;
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

