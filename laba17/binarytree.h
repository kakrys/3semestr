#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>
#include <string>

namespace Tree
{
    class Tree
    {
    public:
        int value;
        Tree* parent;
        Tree* left;
        Tree* right;
        std::string string; // для линейно-скобочной записи.

        Tree(const int v, Tree* p); //конструктор класса дерева
        Tree(); //переопределение конструктора
        Tree(std::string str); // для переприсовения строки
        void add(const int v); // добавить элемент в дерево

        Tree* search(Tree* item, int v); // поиск поддерева по элементу

        Tree* Search(int v);
        void remove(int value);
        std::string toString(int value); // переводит число в строку

        void print(Tree* tree); // переводит дерево в линейно-скобочуню запись
        void Print(); // вывести указатель на print
        void show(); // вывод всеъ элементов
        bool isDigital(const char elem); // проверка на число
        Tree parse(std::string str); // парсит  строку в бинарное дерево
    };

}

#endif //  __BINARY_TREE_H__
