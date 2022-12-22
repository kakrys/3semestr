#include "BinaryTree.hpp"


namespace Tree
{
Elem* MAKE(int data, Elem* p) // Указатель на создание(ф-ию) дерева
{
    Elem* q = new Elem;
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

void StackByPass(Elem*& root)  // Не рекурсивный прямой обход(стек)
{
    std::stack<Elem*> s;
    s.push(nullptr);
    Elem*& parent = root;
    do {
        if (parent != nullptr)
        {
            s.push(parent);
            std::cout << parent->data << " ";
            parent = parent->left;
        }
        else
        {
            if (s.top() == nullptr)
            {
                break;
            }
            parent = s.top();
            s.pop();
            parent = parent->right;
        }
    } while (true); // хотя бы 1 раз, чтобы занести что-то в стек
}


void center(Elem*& root) // центральный обход
{
    if (root != nullptr)
    {
        if (root->left != nullptr)
        {
            center(root->left);
        }
        std::cout << root->data << " ";
        if (root->right != nullptr)
        {
            center(root->right);
        }
    }
}

void bypass(Elem*& root) // прямой обход
{
    if (root == nullptr)
    {
        return;
    }
    std::cout << root->data << " ";
    bypass(root->left);
    bypass(root->right);
}

void EndBypass(Elem*& root) // концевой обход
{
    if (root != nullptr)
    {
        if (root->left != nullptr)
        {
            EndBypass(root->left);
        }
        if (root->right != nullptr)
        {
            EndBypass(root->right);
        }
        std::cout << root->data << " ";
    }
}

void ADD(int data, Elem*& root) // Добавить элемент в дерево
{
    if (root == nullptr)
    {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
        {
            v = v->left;
        }
        else
            v = v->right;
    if (data == v->data)
        return;
    Elem* u = MAKE(data, v);
    if (data < v->data)
    {
        v->left = u;
    }
    else
        v->right = u;
}

void PASS(Elem* v) // Вывести поочерёдно все элементы дерева
{
    if (v == nullptr)
        return;
    PASS(v->left);
    std::cout << v->data << std::endl;
    PASS(v->right);
}

Elem* SEARCH(int data, Elem* v)  // поиск элемента в дереве
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}
void SearchCount(int data, Elem* v, int count)  // подсчёт найденных слов в дереве
{
    if (v == nullptr)
    {
        std::cout << "n";
        return;
    }
    if (v->data == data)
    {
        std::cout << count;
        return;
    }
    if (data < v->data)
    {
        return SearchCount(data, v->left, count + 1);
    }
    else
    {
        return SearchCount(data, v->right, count + 1);
    }
}



void DELETE(int data, Elem*& root) // удалить элемент в дереве
{
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }

    if (u->left == nullptr && u->right != nullptr && u == root) // TODO  u==root
    {
        Elem* t = u->right;
        while (t->left != nullptr)
        {
            t = t->left;
        }
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right == nullptr && u == root) // TODO  u==root
    {
        Elem* t = u->left;
        while (t->right != nullptr)
        {
            t = t->right;
        }
        u->data = t->data;
        u = t;
    }

    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
        {
            t = t->left;
        }
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
    {
        t = u->right;
    }
    else
        t = u->left;
    if (u->parent->left == u)
    {
        u->parent->left = t;
    }
    else
        u->parent->right = t;
    if (t != nullptr)
    {
        t->parent = u->parent;
    }
    delete u;
}

void CLEAR(Elem*& v)  // очистить всё дерево, включая указатели
{
    if (v == nullptr)
        return;
    CLEAR(v->left);
    CLEAR(v->right);

    delete v;
    v = nullptr;
}

}
