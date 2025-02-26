#include "RedBlackLevel.h"

#include "Algorithm/RedBlackTree.h"
#include "Actor/TreeNodeActor.h"
#include "Game/Game.h"


RedBlackLevel::RedBlackLevel()
{
    system("cls");
    tree = new RedBlackTree();
}

RedBlackLevel::~RedBlackLevel()
{
    SafeDelete(tree);
    // 마우스/윈도우 이벤트 활성화.
    HANDLE inputHandle = GetStdHandle(STD_INPUT_HANDLE);
    int flag = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_PROCESSED_INPUT | ENABLE_EXTENDED_FLAGS;
    SetConsoleMode(inputHandle, flag);
    std::ios::sync_with_stdio(false);

}

void RedBlackLevel::Update(float deltaTime)
{
    if (Game::Get().GetKeyDown(VK_RETURN))
    {
        InputNumber();
        PrintRedBlackTree();
    }
    if (Game::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ToggleMenu();
    }
}

void RedBlackLevel::InputNumber()
{
    int input = 0;
    std::cin >> input;
    tree->Insert(input);
}

void RedBlackLevel::PrintRedBlackTree()
{
    for (auto actor : nodeActors)
    {
        actor->RemoveNode();
        actor->Destroy();
    }
    nodeActors.clear();
    PrintRecursive(tree->Root(), Vector2((int)(Game::Get().ScreenSize().x*0.5f), 1));
}

void RedBlackLevel::PrintRecursive(TreeNode* node, const Vector2& nowPostion, int depth)
{
    if (node == tree->Nil())
    {
        return;
    }

    int xSize = Game::Get().ScreenSize().x;
    int leftPosition = (int)(-xSize * 0.25f);
    int rightPosition = (int)(xSize * 0.25f);
    Vector2 nowPosition = nowPostion;
    TreeNodeActor* nodeActor = nullptr;

    if (node->Parent())
    {
        if (node == node->Parent()->Left())
        {
            nowPosition = nowPosition + Vector2(leftPosition / depth, 2);
        }
        else
        {
            nowPosition = nowPosition + Vector2(rightPosition / depth, 2);
        }
    }
    
    nodeActor = new TreeNodeActor(node, nowPosition);
    AddActor(nodeActor);
    nodeActors.emplace_back(nodeActor);

    // 하위 노드 출력.
    PrintRecursive(node->Left(), nowPosition, depth + 1);
    PrintRecursive(node->Right(), nowPosition, depth + 1);

}


