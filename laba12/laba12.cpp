// внешняя многофазная SORT
#include <fstream>
#include <iostream>

int main()
{
	std::ifstream in, in1, in2; 
	std::ofstream out, out1, out2; 
	int a, b = 0;
	int size = 0; 	// кол-во чисел в файле
	int p, t, count = 0;
	bool flag = true;
	bool A_full, B_full = true;
	in.open("input.txt");
	out.open("exit.txt");

	while (in >> a)
	{
		out << a << " ";
		size++;
	}

	in.close();
	out.close();
	for (int i = 1; i < size; i *= 2) // домножаем на 2, т.к. работаем с 1, потом 2, 4, 8, .... 2*k, i=k
	{
		// Дробим на два файла, чтобы уместить больше макс. возможного кол-ва чисел в одном файле
		in.open("exit.txt");
		out1.open("A.txt");
		out2.open("B.txt");
		count = 0;
		while (in >> a)
		{
			count++;
			if (flag)
				out1 << a << " ";
			else
				out2 << a << " ";

			if (count == i)
			{
				count = 0;
				flag = !flag;
			}
		}

		in.close();
		out1.close();
		out2.close();

		in1.open("A.txt");
		in2.open("B.txt");
		out.open("exit.txt");

		// Сливаем файлы в один, упорядочивая их сразу после сортировки
		if (in1 >> a)
		{
			A_full = true;
		}
		else
		{
			A_full = false;
		}
		if (in2 >> b)
		{
			B_full = true;
		}
		else
		{
			B_full = false;
		}
		// Аналогично сливаем, только уже по четвертям
		for (int j = 0; j < size; j += 2 * i)
		{
			p = 0; t = 0;
			while (p < i && A_full && t < i && B_full)
				if (a < b)
				{
					out << a << " ";
					if (in1 >> a)
					{
						A_full = true;
					}
					else
					{
						A_full = false;
					}
					p++;
				}
				else
				{
					out << b << " ";
					if (in2 >> b)
					{
						B_full = true;
					}
					else
					{
						B_full = false;
					}
					t++;
				}
			// Повторяем до полного слияния всего первоначального файла в новый, уже отсортированный
			while (p < i && A_full)
			{
				out << a << " ";
				if (in1 >> a)
				{
					A_full = true;
				}
				else
				{
					A_full = false;
				}
				p++;
			}
			while (t < i && B_full)
			{
				out << b << " ";
				if (in2 >> b)
				{
					B_full = true;
				}
				else
				{
					B_full = false;
				}
				t++;
			}

		}

		in1.close();
		in2.close();
		out.close();

		remove("A.txt");
		remove("B.txt"); // удаляем их, чтобы не оставлять после использования
	}

	return 0;
}