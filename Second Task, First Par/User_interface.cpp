#include "user_interface.h"



int getValue(int condition, const char* string)
{
	while (true)													// ���� ������������ �� ��� ���, ���� ������������ �� ������ ���������� ��������
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// ���� ���������� ���������� ��������� ���������,
		{
			std::cout << "������! ����������, ��������� ����! \n";
			std::cin.clear();										// �� ���������� cin � '�������' ����� ������
			std::cin.ignore(32767, '\n');							// � ������� �������� ����������� ����� �� �������� ������
			std::cout << string;
		}
		else // ���� �� ������ � ���������� �������, �� ���������� a
		{
			switch (condition)
			{

			case O_Or_1:												// �� �������

				if (a == 0 || a == 1) { return a; }

				std::cout << "�� ������ ������ ���� 0, ���� 1\n";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			case Menu_Commands:

				if ((a > 0) && (a < 8)) { return a; }

				std::cout << "� ���� ����� 7 �������! ��������� ����: ";
				std::cin.ignore(32767, '\n');						// � ������� �������� ����������� ����� �� �������� ������
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout << "  ���������� ���������:\n"
		<< "1. ������������� �����\n"
		<< "2. ���������� ������ ��������\n"
		<< "3. �������� �������� �����\n"
		<< "4. �������� ���������� �����\n"
		<< "5. �������� ������� ����\n"
		<< "6. ������� ������ ���������\n"
		<< "\n7. ���������� ������\n\n";
}

void write_author()
{
	std::cout << "������ �������� ������ �.�., ������ 4211\n";
}


void menu(My_Stack::stackElement*& stack)
{
	int user_choice = 0;

	show_main_menu();
	std::cout << "�������� �������: ";
	user_choice = getValue(Menu_Commands, "�������� �������: ");

	while (user_choice != Exit)
	{
		switch (user_choice)
		{
			int temp_data;

		case Init_stack:

			if (!stack)
			{
				std::cout << "������� ������: "; temp_data = getValue(1, "������� ������: ");
				stack = My_Stack::init(temp_data);
			}
			else
			{
				std::cout << "���� ��� ���������������!\n";
			}
			break;

		case Add_new_element:

			if (stack)
			{
				std::cout << "������� ������: "; temp_data = getValue(1, "������� ������: ");
				My_Stack::add(stack, temp_data);
			}
			else
			{
				std::cout << "���������� ��������� ��������, �.� ���� �� ���������������\n";
			}

			break;

		case Delete_last_element:

			My_Stack::remove_at(stack);
			break;

		case Show_stack:

			if (stack) { My_Stack::show(stack); }
			else { std::cout << "���� �� ���������������!\n"; }

			break;

		case Show_main_menu:

			std::cout << "\n\n";
			show_main_menu();
			break;

		case Write_author:

			write_author();
			break;

		default:
			break;
		}
		std::cout << "\n�������� �������: ";
		user_choice = getValue(Menu_Commands, "�������� �������: ");
	}

}