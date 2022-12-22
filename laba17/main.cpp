#include "binarytree.h"

int main()
{
    std::string str = "4(3(41,6(4,87)),43(,9474(5756,)))";

    Tree::Tree tree;

    tree = tree.parse(str);

    Tree::Tree newTree = tree;
    newTree.remove(10);
    newTree.show();


    return 0;
}
