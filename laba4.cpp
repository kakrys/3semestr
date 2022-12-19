<<<<<<< HEAD
//���������� ������� ������������
=======
..���������� ������� ������������
>>>>>>> master
//� ������ ������ ��������� O(nlog(n)), � ������ � O(n2).
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

/*  
�������������� ������ ����� ������������� ����� � ������ ����������� �������� ���������� �������� ����������, ����������� �������� ������� ����� �������� 1.2473309. 
������� ���������� ����� ���������� ����� ������� ������� ����������� �� ������ ���������� (��������� ����������� �� ���������� ������). 
�����, ������ ������ � ���� �����, �� ����� ����� ��� �� ������ ���������� � �������� �� ������ �����. 
��� ������������ �� ��� ���, ���� �������� �������� �� ��������� �������. � ���� ������ ������ ����������������� ������� ���������.
*/

void combSort(std::vector<int>& array)
{
	int gap = array.size();
	bool flag = true;

	while (gap != 1 || flag == true)
	{
		gap = (gap) / 1.3; // ������ ����������, ������� ����������� ������ ��������, �� ����� � �������� ������������ 1.247
		if (gap < 1)
			gap = 1;
		flag = false;

		for (int i = 0; i < array.size() - gap; i++)
		{
			if (array[i] > array[i + gap])
			{
				std::swap(array[i], array[i + gap]);
				flag = true;
			}
		}
	}
}
int main()
{
	srand(static_cast <unsigned int> (time(0))); // ����� ���. �����(��� �����������)
	setlocale(LC_ALL, "RUS");
	int N;
	std::vector <int> mas;
	std::cout << "������� ����� ��������� ����� � ������� = ";
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		mas.push_back(rand());
	}
	std::cout << "\n ������ ����� ��� ����������:\n";
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "\n ������ ����� ����� ����������:\n";
	combSort(mas);
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
<<<<<<< HEAD
}
=======
}
>>>>>>> master