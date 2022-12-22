#include "binarytree.h"


namespace Tree
{
    Tree::Tree(const int v, Tree* p) //конструктор класса дерева
    {
        value = v;
        parent = p;
    }
    Tree::Tree() {} //переопределение конструктора
    Tree::Tree(std::string str) // для переприсовения строки
    {
        string = str;
    }

    void Tree::add(const int v) // добавить элемент в дерево
    {
        if (v >= value)
        {
            if (right == nullptr)
            {
                right = new Tree(v, this);
            }
            else
            {
                right->add(v);
            }
        }
        else
        {
            if (left == nullptr)
            {
                left = new Tree(v, this);
            }
            else
            {
                left->add(v);
            }
        }
    }

    Tree* Tree::search(Tree* item, int v) // поиск поддерева по элементу
    {
        if (item == nullptr || item->value == v)
        {
            return item;
        }
        if (item != nullptr && item->value > v)
        {
            return search(item->left, v);
        }
        if (item != nullptr && item->value < v)
        {
            return search(item->right, v);
        }
    }

    Tree* Tree::Search(int v)
    {
        return search(this, v);
    }

    void Tree::remove(int value)
    {
        Tree* item = this->Search(value);
        if (item == nullptr) return;
        Tree* currentTree = nullptr;

        // удаление корня

        if (this == item)
        {
            if (item->right != nullptr)
            {
                currentTree = item->right;
                while (currentTree->left != nullptr)
                {
                    currentTree = currentTree->left;
                }

            }
            else if (item->left != nullptr)
            {
                currentTree = item->left;
                while (currentTree->right != nullptr)
                {
                    currentTree = currentTree->right;
                }
            }

            int val = currentTree->value;
            remove(val);
            item->value = val;

        }
        // удаление листьев
        else if (item->left == nullptr && item->right == nullptr && item->parent != nullptr)
        {
            if (item->parent->right == item)
            {
                item->parent->right = nullptr;
            }
            else
            {
                item->parent->left = nullptr;
            }
        }
        // удаление узла, который имеет левого потомка.
        else if (item->left != nullptr && item->right == nullptr && item->parent != nullptr)
        {
            item->left->parent = item->parent;
            if (item == item->parent->left)
            {
                *item->parent->left = *item->left;
            }
            else if (item == item->parent->right)
            {
                *item->parent->right = *item->left;
            }

        }
        // удаление узла, который имеет правого потомка.
        else if (item->left == nullptr && item->right != nullptr && item->parent != nullptr)
        {
            item->right->parent = item->parent;
            if (item == item->parent->left)
            {
                *item->parent->left = *item->right;
            }
            else if (item == item->parent->right)
            {
                *item->parent->right = *item->right;
            }

        }
        // удаление узла, который имеет оба потомка.
        else if (item->left != nullptr && item->right != nullptr && item->parent != nullptr)
        {
            currentTree = item->right;
            if (currentTree->left != nullptr)
            {
                while (currentTree->left != nullptr)
                {
                    currentTree = currentTree->left;
                }
                if (currentTree->right != nullptr)
                {
                    currentTree->right->parent = currentTree->parent;
                    currentTree->parent->left = currentTree->right;
                }
                else
                {
                    currentTree->parent->left = nullptr;
                }
                item->left->parent = currentTree;
                currentTree->left = item->left;
                if (item->parent->right == item)
                {
                    currentTree->parent = item->parent->right;
                    item->parent->right = currentTree;
                }
                else
                {
                    currentTree->parent = item->parent->left;
                    item->parent->left = currentTree;
                }
                currentTree->right = item->right;
                item->right->parent = currentTree;
            }
            else
            {
                item->left->parent = currentTree;
                currentTree->left = item->left;
                currentTree->parent = item->parent;
                if (item->parent->left == item)
                {
                    item->parent->left = currentTree;
                }
                else
                {
                    item->parent->right = currentTree;
                }
            }

        }


    }
    std::string  Tree::toString(int value) // переводит число в строку
    {
        std::string result;

        if (value > 9)
        {
            result += char(value / 10 + 48);
            result += char(value % 10 + 48);
        }
        else
        {
            result += char(value + 48);
        }

        return result;
    }
    void  Tree::print(Tree* tree) // переводит дерево в линейно-скобочуню запись
    {
        string += toString(tree->value);
        if (tree->left != nullptr || tree->right != nullptr)
        {
            string += '(';
            if (tree->left != nullptr)
            {
                print(tree->left);
            }
            string += ',';
            if (tree->right != nullptr)
            {
                print(tree->right);
            }
            string += ')';
        }

    }
    void Tree::Print() // вывести указатель на print
    {
        print(this);
    }

    void  Tree::show() // вывод всеъ элементов
    {
        print(this);

        for (const auto& elem : string)
        {
            std::cout << elem;
        }
    }

    bool  Tree::isDigital(const char elem) // проверка на число
    {
        return (elem >= '0' && elem <= '9') ? true : false;
    }

    Tree  Tree::parse(std::string str) // парсит  строку в бинарное дерево
    {
        Tree result;
        int index;
        if (isDigital(str[0]) && isDigital(str[1]))
        {
            int val = (str[0] - 48) * 10 + str[1] - 48;
            result.value = val;
            index = 2;
        }
        else if (isDigital(str[0]) && !isDigital(str[1]))
        {
            int val = str[0] - 48;
            result.value = val;
            index = 1;
        }


        for (int i = index; i < str.size() - 1;)
        {
            if (isDigital(str[i]) && isDigital(str[i + 1]))
            {
                int value = (str[i] - 48) * 10 + str[i + 1] - 48;
                result.add(value);
                i += 2;
            }
            else if (isDigital(str[i]) && !isDigital(str[i + 1]))
            {
                int value = str[i] - 48;
                result.add(value);
                i++;
            }
            else
            {
                i++;
            }
        }
        return result;
    }
}
