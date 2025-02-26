#pragma once
#include "Actor/DrawableActor.h"

class TreeNode;
class TreeNodeActor : public DrawableActor
{
    RTTI_DECLARATIONS(TreeNodeActor, DrawableActor)
public:
    TreeNodeActor(TreeNode* treeNode, const Vector2& position);
    ~TreeNodeActor();
    void RemoveNode() { treeNode = nullptr; }
    void SetColor();
private:
    TreeNode* treeNode = nullptr;

};