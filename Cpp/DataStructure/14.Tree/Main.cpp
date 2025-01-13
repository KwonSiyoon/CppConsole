#include <iostream>
#include "String.h"
#include "Node.h"
#include "Tree.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>



int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Tree<String> tree("A");
    tree.AddChild("B");
    tree.AddChild("B", "E");
    tree.AddChild("B", "F");
    tree.AddChild("B", "G");

    tree.AddChild("C");
    tree.AddChild("C", "H");

    tree.AddChild("D");
    tree.AddChild("D", "I");
    tree.AddChild("D", "J");
    
    // 검색 테스트.
    Node<String>* outNode = nullptr;
    if (tree.Find("D", &outNode))
    {
        std::cout << "D 노드 검색 성공. 노드 수 : " << outNode->GetCount() << "\n";
    }
    else
    {
        std::cout << "D 노드 검색 실패\n";
    }

    // 전위 순회.
    std::cout << "---- 전위 순회 ----\n";
    tree.PreorderTraverse();

    std::cin.get();

}