#include "HashFunc.h"
namespace hash
{
    int Hashfunc(int a) // Сама хэш-функция
    {
        int b = a % N;
        return b;
    }

    void HashTable(int mas[N][N], int a) // заполнение матрицы хэширования
    {
        int b = Hashfunc(a);
        if (mas[b][0] == 0)
        {
            mas[b][0] = a;
        }
        else
        {
            for (int i = 1; i < N; i++)
            {
                if (mas[b][i] == 0)
                {
                    mas[b][i] = a;
                    break;
                }
            }
        }
    }

    void out(int mas[N][N]) // вывод того, что было хешировано
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mas[i][j] != 0)
                {
                    std::cout << mas[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }

    int foundN(int y) // поиск какого-то элемента в хэш-функции
    {
        int a = Hashfunc(y);
        return a;
    }

    void foundNubmers(int mas[N][N], int k) // поиск нескольких номеров
    {
        for (int i = 0; i < N; i++)
        {
            if (mas[k][i] != 0)
            {
                std::cout << "foundNumbers: " << mas[k][i] << " ";
            }
            else
            {
                break;
            }
        }
    }
}
