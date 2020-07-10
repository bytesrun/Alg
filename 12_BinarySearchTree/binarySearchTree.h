#include <iostream>
#include <vector>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *p;
	TreeNode() : val(0), left(nullptr), right(nullptr), p(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr), p(nullptr) {} 	
};

void buildBST(TreeNode *dummy, std::vector<int>& nums);
void TreeFirstOrderWalk(TreeNode* root);
void TreeInOrderWalk(TreeNode* root);
void TreePostOrderWalk(TreeNode* root);
TreeNode* BstSearch_r(TreeNode* root, int key);
TreeNode* BstSearch_i(TreeNode* root, int key);
TreeNode* BstInsert(TreeNode*& root, int key);
void BstDel(TreeNode* root, int key);

void TestBST();