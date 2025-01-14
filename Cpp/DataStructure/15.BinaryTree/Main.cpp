#include <iostream>
#include <string>
#include "BinaryTree.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 트리 생성.
    BinaryTree<const char*> tree("1");
    tree.AddLeftChild("1","2");
    tree.AddRightChild("2", "5");
    tree.AddLeftChild("2","4");
    tree.AddLeftChild("4","8");
    tree.AddRightChild("4", "9");
    tree.AddLeftChild("5","10");
    tree.AddRightChild("5", "11");

    tree.AddRightChild("1", "3");
    tree.AddLeftChild("3","6");
    tree.AddRightChild("3", "7");
    tree.AddLeftChild("6","12");
    tree.AddRightChild("6", "13");
    tree.AddLeftChild("7","14");
    tree.AddRightChild("7", "15");

    // 출력.
    tree.PreorderTraverse();

    // 삭제.
    tree.DeleteNode("6");
    tree.PreorderTraverse();

    std::cin.get();
}