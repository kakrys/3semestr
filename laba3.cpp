#include <iostream>
#include <vector>
#include <algorithm>
/*На вход дается одно число х, нужно вывести все числа от 1 до х, удовлетворяющие условию :
3 ^ K * 5 ^ L * 7 ^ M = xi
где K, L, M - натуральные числа или могут быть равны 0.
*/
int main()
{
	setlocale(LC_ALL, "RUS");
	long long x;
	std::cout << "Введите число x = ";
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