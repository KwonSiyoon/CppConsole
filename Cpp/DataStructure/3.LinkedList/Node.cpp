#include "Node.h"

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	os << "Data: " << node.data;
	return os;
}

Node::Node()
{
}

Node::Node(int data)
	: data(data)
{
}
