#include <iostream>
#include <vector>
#include <string>
int main()
{
	std::vector <char> mas;
	setlocale(LC_ALL, "RUS");
	std::cout << "Введите последовательность скобок: ";

	std::string str;
	std::cin >> str;
<<<<<<< HEAD
	for (int i = 0; i < str.size(); i++) // перебор по количеству символов в строке.
=======
	for (int i = 0; i < str.size(); i++) // перебор по количеству символов в строке
>>>>>>> master
	{
		if ((i != 0) && (mas.size() > 0)) // проверка на то, что массив не пустой, и начинаем отбор не с первого числа(т.к. изначально в нём ничего нет), и ему необходимо заполниться
		{
			if (((mas.back() == '{') && (str[i] == '}')) || ((mas.back() == '(') && (str[i] == ')')) || ((mas.back() == '[') && (str[i] == ']')))
			{
				mas.pop_back();
			}
			else
			{
				mas.push_back(str[i]);
			}
		}
		else
		{
			mas.push_back(str[i]);
		}
	}

	if (mas.size() > 0)
	{
		std::cout << "Строка не существует";
	}
	else
	{
		std::cout << "Строка существует";
	}

	return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> master