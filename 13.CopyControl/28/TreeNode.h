#pragma once
#include <string>

class TreeNode
{
	friend class BinStrTree;
public:
	TreeNode(const std::string &val = std::string());
	TreeNode(const TreeNode &);
	TreeNode operator=(const TreeNode &);
	~TreeNode();

private:
	std::string value;
	int *count;
	TreeNode *left;
	TreeNode *right;
};
