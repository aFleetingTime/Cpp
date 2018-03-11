#include "TreeNode.h"
#include <iostream>

class BinStrTree
{
public:
	BinStrTree();
	~BinStrTree();
	BinStrTree(const BinStrTree &);
	BinStrTree& operator=(const BinStrTree &);
	bool insert(const std::string &s);
	void print();
	
private:
	TreeNode *root;
	void printTree(TreeNode *node);
	bool insertTree(const std::string &s, TreeNode *&node);
};
