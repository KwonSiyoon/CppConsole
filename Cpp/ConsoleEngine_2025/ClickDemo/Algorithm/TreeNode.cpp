#include "TreeNode.h"

TreeNode::TreeNode(int data, NodeColor color)
    : data(data), color(color)
{
}

const char* TreeNode::ColorString() const
{
    return color == NodeColor::Red ? "RED" : "BLACK";
}
