#include <iostream>
#include <vector>
#include <algorithm>
/*�� ���� ������ ���� ����� �, ����� ������� ��� ����� �� 1 �� �, ��������������� ������� :
3 ^ K * 5 ^ L * 7 ^ M = xi
��� K, L, M - ����������� ����� ��� ����� ���� ����� 0.
*/
int main()
{
	setlocale(LC_ALL, "RUS");
	long long x;
	std::cout << "������� ����� x = ";
	std::cin >> x;
	long long tk = 1;
	std::vector <long long> mas;
	while (tk <= x)
	{
		long long tl = tk;
		while (tl <= x)
		{
			long long tm = tl;
			while (tm <= x)
			{
				mas.push_back(tm);
				tm *= 7;
			}
			tl *= 5;
		}
		tk *= 3;
	}
	std::sort(mas.begin(), mas.end());
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas.at(i) <<'\n';
	}
}