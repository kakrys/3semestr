#include <iostream>
#include <BinaryTree.hpp>

int main()
{
        Tree::Elem* root = nullptr; // создаём нулевое дерево
        int N = 20; // количество чисел в дереве
        srand(time(0)); // рандом, зависящий от текущего времени
        for (int i = 0; i < N; i++)
        {
            int a = i * rand() % 100;
            Tree::ADD(a, root); // добавляем каждый элемент в дерево
        }
        Tree::PASS(root); // выводим дерево

        std::cout << "\nCenter: "; // центральный обход
        Tree::center(root);
        std::cout << "\nByPass: "; // прямой обход
        Tree::bypass(root);
        std::cout << "\nEndByPass: "; // концевой обход
        Tree::EndBypass(root);
        std::cout << "\n\n\n";
        Tree::CLEAR(root); // очищаем память, удаляя дерево и все указатели
        return 0;
}
