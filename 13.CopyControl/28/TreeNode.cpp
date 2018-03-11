#include "TreeNode.h"

TreeNode::TreeNode(const std::string &val) : value(val), count(new int(1)), left(nullptr), right(nullptr)
{
	;
}

TreeNode::TreeNode(const TreeNode &node) : value(node.value), count(&++(*node.count)), left(node.left), right(node.right)
{
	;
}

TreeNode TreeNode::operator=(const TreeNode &node)
{
	++*node.count;
	if(--*count == 0)
		delete left, delete right, delete count;
	count = node.count;
	left = node.left;
	right = node.right;
	value = node.value;
	return *this;
}

TreeNode::~TreeNode()
{
	if(--*count == 0)
		delete left, delete right, delete count;
	left = nullptr, right = nullptr, count = nullptr;
}
