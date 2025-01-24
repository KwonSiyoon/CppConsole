#include <iostream>
#include "BinarySearchTree.h"


int main()
{
    // 이진 탐색 트리 생성.
    BinarySearchTree<int> tree;

    // 노드 추가.
    tree.InsertNode(50);
    tree.InsertNode(50);
    tree.InsertNode(40);
    tree.InsertNode(30);
    tree.InsertNode(80);
    tree.InsertNode(60);

    int searchData = 90;
    if (tree.SearchNode(searchData))
    {
        std::cout << searchData << " 검색 성공.\n";
    }
    else
    {
        std::cout << searchData << " 검색 실패.\n";
    }
    
    int keyToDelete = 30;
    if (tree.DeleteNode(keyToDelete))
    {
        std::cout << keyToDelete << " 노드 삭제 성공\n";
    }
    else
    {
        std::cout << keyToDelete << " 노드 삭제 실패\n";
    }

    tree.InorderTraverse();

    std::cin.get();
}