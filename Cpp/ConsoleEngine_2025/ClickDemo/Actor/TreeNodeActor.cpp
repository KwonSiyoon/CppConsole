#include "TreeNodeActor.h"
#include "Algorithm/TreeNode.h"

TreeNodeActor::TreeNodeActor(TreeNode* treeNode, const Vector2& position)
    : treeNode(treeNode)
{
    char buffer[20];
    sprintf_s(buffer, sizeof(buffer), "%d", treeNode->Data());
    SafeDelete(image);
    auto length = strlen(buffer) + 1;
    this->image = new char[length];
    strcpy_s(this->image, length, buffer);
    SetColor();
    SetPosition(position);
}

TreeNodeActor::~TreeNodeActor()
{
    treeNode = nullptr;
}

void TreeNodeActor::SetColor()
{
    if (treeNode->GetColor() == NodeColor::Red)
    {
        color = Color::Red;
    }
    else
    {
        color = Color::White;
    }
}
