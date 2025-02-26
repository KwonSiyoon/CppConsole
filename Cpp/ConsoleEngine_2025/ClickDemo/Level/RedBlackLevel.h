#pragma once
#include "Level/Level.h"

class Vector2;
class TreeNodeActor;
class RedBlackLevel : public Level
{
    RTTI_DECLARATIONS(RedBlackLevel, Level)
public:
    RedBlackLevel();
    ~RedBlackLevel();

    virtual void Update(float deltaTime) override;
    void InputNumber();
    void PrintRedBlackTree();
private:
    void PrintRecursive(class TreeNode* node, const Vector2& nowPostion, int depth = 0);

private:
    class RedBlackTree* tree = nullptr;
    std::vector<TreeNodeActor*> nodeActors;

};
