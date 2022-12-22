#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include <iostream>
#include <stack>

namespace Tree
{
    struct Elem
    {
        int data;
        Elem* left;
        Elem* right;
        Elem* parent;
    };
    Elem* MAKE(int data, Elem* p);
    void ADD(int data, Elem*& root);
    void PASS(Elem* v);
    Elem* SEARCH(int data, Elem* v);
    void SearchCount(int data, Elem* v, int count);
    void DELETE(int data, Elem*& root);
    void CLEAR(Elem*& v);
    void center(Elem*& root); // центральный обход
    void bypass(Elem*& root); // прямой обход
    void EndBypass(Elem*& root); // концевой обход
    void StackByPass(Elem*& root); // Не рекурсивный прямой обход(стек)
}

#endif //  __BINARY_TREE_H__
