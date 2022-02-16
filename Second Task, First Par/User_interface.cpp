#include "user_interface.h"



int getValue(int condition, const char* string)
{
	while (true)													// цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		std::cin >> a;

		if (std::cin.fail())										// если предыдущее извлечение оказалось неудачным,
		{
			std::cout << "Ошибка! Пожалуйста, повторите ввод! \n";
			std::cin.clear();										// то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n');							// и удаляем значения предыдущего ввода из входного буфера
			std::cout << string;
		}
		else // если всё хорошо и выполнятся условия, то возвращаем a
		{
			switch (condition)
			{

			case O_Or_1:												// На будущее

				if (a == 0 || a == 1) { return a; }

				std::cout << "Вы должны ввести либо 0, либо 1\n";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			case Menu_Commands:

				if ((a > 0) && (a < 8)) { return a; }

				std::cout << "У меню всего 7 функций! Повторите ввод: ";
				std::cin.ignore(32767, '\n');						// и удаляем значения предыдущего ввода из входного буфера
				continue;

			default:
				return a;
			}

		}

	}
}

void show_main_menu()
{
	std::cout << "  Функционал программы:\n"
		<< "1. Инициализация стека\n"
		<< "2. Добавление нового элемента\n"
		<< "3. Удаление элемента стека\n"
		<< "4. Показать содержимое стека\n"
		<< "5. Показать главное меню\n"
		<< "6. Вывести автора программы\n"
		<< "\n7. Завершение работы\n\n";
}

void write_author()
{
	std::cout << "Работу выполнил Калеев Д.А., группа 4211\n";
}


void menu(My_Stack::stackElement*& stack)
{
	int user_choice = 0;

	show_main_menu();
	std::cout << "Выберите команду: ";
	user_choice = getValue(Menu_Commands, "Выберите команду: ");

	while (user_choice != Exit)
	{
		switch (user_choice)
		{
			int temp_data;

		case Init_stack:

			if (!stack)
			{
				std::cout << "Введите данные: "; temp_data = getValue(1, "Введите данные: ");
				stack = My_Stack::init(temp_data);
			}
			else
			{
				std::cout << "Стек уже инициализирован!\n";
			}
			break;

		case Add_new_element:

			if (stack)
			{
				std::cout << "Введите данные: "; temp_data = getValue(1, "Введите данные: ");
				My_Stack::add(stack, temp_data);
			}
			else
			{
				std::cout << "Невозможно выполнить операцию, т.к стек не инициализирован\n";
			}

			break;

		case Delete_last_element:

			My_Stack::remove_at(stack);
			break;

		case Show_stack:

			if (stack) { My_Stack::show(stack); }
			else { std::cout << "Стек не инициализирован!\n"; }

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
		std::cout << "\nВыберите команду: ";
		user_choice = getValue(Menu_Commands, "Выберите команду: ");
	}

}