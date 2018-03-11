#include "BinStrTree.h"

BinStrTree::BinStrTree() : root(nullptr)
{
	;
}

BinStrTree::~BinStrTree()
{
	delete root;
	root = nullptr;
}

BinStrTree::BinStrTree(const BinStrTree &tree) : root(new TreeNode(*tree.root))
{
	;
}

BinStrTree& BinStrTree::operator=(const BinStrTree &tree)
{
	auto temp = new TreeNode(*tree.root);
	delete root;
	root = temp;
	return *this;
}

bool BinStrTree::insert(const std::string &s)
{
	return insertTree(s, root);
}

void BinStrTree::printTree(TreeNode *node)
{
	if(!node)
		return;
	printTree(node->left);
	std::cout << node->value << std::endl;
	printTree(node->right);
}

void BinStrTree::print()
{
	printTree(root);
}

bool BinStrTree::insertTree(const std::string &s, TreeNode *&node)
{
	if(!node)
	{
		node = new TreeNode(s);
		return true;
	}
	else if(node->value > s)
		insertTree(s, node->left);
	else if(node->value < s)
		insertTree(s, node->right);
	return false;
}
