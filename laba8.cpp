/* №8 Поразрядная сортировка */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

int digit(int n, int k, int N, int M) 
{
	return (n >> (N * k) & (M - 1));
}

void _radixsort(int* l, int* r, int N) 
{ //O(k * M)
	int k = (32 + N - 1) / N;
	int M = 1 << N;
	int sz = r - l;
	int* b = new int[sz];
	int* c = new int[M];
	for (int i = 0; i < k; i++) 
	{//O(k * M)
		for (int j = 0; j < M; j++)
		{//O(M)
			c[j] = 0;
		}
		for (int* j = l; j < r; j++)
		{//O(N)
			c[digit(*j, i, N, M)]++;
		}
		for (int j = 1; j < M; j++)
		{//O(M)
			c[j] += c[j - 1];
		}
		for (int* j = r - 1; j >= l; j--)
		{//O(N)
			b[--c[digit(*j, i, N, M)]] = *j;
		}
		int cur = 0;
		for (int* j = l; j < r; j++)
		{//O(N)
			*j = b[cur++];
		}
	}
	delete b;
	delete c;
}
void radixsort(int* l, int* r) // метод для вызова самой сортировки(через сам массив и массив + его длину)
{ //O(k * M)
	_radixsort(l, r, 8); //O(k * M), берём по 8 бит
}

/*Асимптотика в худшем случае – O(w*n) где w — количество бит, требуемых для хранения каждого ключа(в моём случае w = 8), затраты памяти O(w*n)*/

int main()
{
	srand(static_cast <unsigned int> (time(0))); // Время сис. часов(где компилируют)
	setlocale(LC_ALL, "RUS");
	int N;	
	std::cout << "Введите число рандомных чисел в массиве = ";
	std::cin >> N;
	int* arr = new int[N];	// создаём дин. массив
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand();
	}
	std::cout << "\nМассив чисел без сортировки:\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\nМассив чисел после сортировки:\n";
	radixsort(arr, arr + N);
	for (int i = 0; i < N; i++)
	{
		std::cout << arr[i] << " ";
	}
}