#include <iostream>
#include <vector>
#include <string>
int main()
{
	std::vector <char> mas;
	setlocale(LC_ALL, "RUS");
	std::cout << "������� ������������������ ������: ";

	std::string str;
	std::cin >> str;
	for (int i = 0; i < str.size(); i++) // ������� �� ���������� �������� � ������
	{
		if ((i != 0) && (mas.size() > 0)) // �������� �� ��, ��� ������ �� ������, � �������� ����� �� � ������� �����(�.�. ���������� � �� ������ ���), � ��� ���������� �����������
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
		std::cout << "������ �� ����������";
	}
	else
	{
		std::cout << "������ ����������";
	}

	return 0;
}