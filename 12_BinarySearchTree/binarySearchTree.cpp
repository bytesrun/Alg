#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "binarySearchTree.h"
#include "InitNums.h"
using namespace std;
TreeNode* buildBST(vector<int>& nums, int st, int ed) {
	if (st >= ed) return nullptr;
	int mid = st + (ed - st) / 2;
	TreeNode *nd = new TreeNode(nums[mid]);
	nd->left = buildBST(nums, st, mid);
	if (nd->left) nd->left->p = nd;
	nd->right = buildBST(nums, mid + 1, ed);
	if (nd->right) nd->right->p = nd;
	return nd;
}
void buildBST(TreeNode *dummy, vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return;
	dummy->left = buildBST(nums, 0, nums.size());
}
void TreeFirstOrderWalk(TreeNode* root) {
	if (!root) return;
	cout << root->val << " ";
	TreeFirstOrderWalk(root->left);
	TreeFirstOrderWalk(root->right);
}
void TreeFirstOrderWalk_ir(TreeNode* root) {
	if (!root) return;
	TreeNode *cur = root;
	while (cur) {
		if (!cur->left) {
			cout << cur->val << " ";
			cur = cur->right;
		}
		else {
			TreeNode *subLr = cur->left;			
			while (subLr->right && subLr->right != cur) {
				subLr = subLr->right;
			}
			if (subLr->right == nullptr) {
				subLr->right = cur;
				cout << cur->val << " ";
				cur = cur->left;
			}
			else {
				subLr->right = nullptr;
				cur = cur->right;
			}
		}
	}
}

void TreeInOrderWalk(TreeNode* root) {
	if (!root) return;
	TreeInOrderWalk(root->left);
	cout << root->val << " ";
	TreeInOrderWalk(root->right);
}

void TreeInOrderWalk_ir(TreeNode* root) {
	if (!root) return;
	TreeNode *cur = root;
	while (cur) {
		if (!cur->left) {
			cout << cur->val << " ";
			cur = cur->right;
		}
		else {
			TreeNode *subLr = cur->left;
			while (subLr->right && subLr->right != cur) {
				subLr = subLr->right;
			}
			if (subLr->right == nullptr) {
				subLr->right = cur;
				cur = cur->left;
			}
			else {
				cout << cur->val << " ";
				subLr->right = nullptr;
				cur = cur->right;
			}			
		}
	}
}
void TreePostOrderWalk(TreeNode* root) {
	if (!root) return;
	TreePostOrderWalk(root->left);
	TreePostOrderWalk(root->right);
	cout << root->val << " ";
}

void reverseWalk(TreeNode* st, TreeNode* ed) {
	vector<int> dt;
	while (st != ed) {
		dt.push_back(st->val);
		st = st->right;
	}
	dt.push_back(st->val);
	copy(dt.rbegin(), dt.rend(), ostream_iterator<int>(std::cout, " "));
}

void TreePostOrderWalk_ir(TreeNode* root) {
	if (!root) return;
	TreeNode dummy(-1);
	dummy.left = root;
	TreeNode *prev = nullptr;
	TreeNode *cur = &dummy;
	while (cur) {
		if (!cur->left) {
			prev = cur;
			cur = cur->right;
		}
		else {
			TreeNode *subLr = cur->left;
			while (subLr->right && subLr->right != cur) {
				subLr = subLr->right;
			}
			if (subLr->right == nullptr) {
				subLr->right = cur;
				prev = cur;
				cur = cur->left;
			}
			else {
				reverseWalk(cur->left, prev);
				prev = cur;
				subLr->right = nullptr;
				cur = cur->right;				
			}
		}
	}
}
TreeNode* BstSearch_r(TreeNode* root, int key) {
	if (!root) return nullptr;
	if (root->val == key) return root;
	if (root->val > key) return BstSearch_r(root->left, key);
	return BstSearch_r(root->right, key);
}
TreeNode* BstSearch_i(TreeNode* root, int key) {
	//if (!root) return nullptr;
	while (root) {
		if (root->val == key) return root;
		if (root->val > key) 
			root = root->left;
		else 
			root = root->right;
	}
	return nullptr;
}
TreeNode* BstInsert(TreeNode*& root, int key) {
	TreeNode *nd = new TreeNode(key);
	TreeNode *y = nullptr;
	TreeNode *x = root;
	while (x) {
		y = x;
		if (x->val > key) {
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	
	if (!y) root = nd;
	else {
		nd->p = y;
		if (y->val > key) {
			y->left = nd;
		}
		else {
			y->right = nd;
		}
	}	
	return nd;
}

TreeNode* successor(TreeNode* nd) {
	if (nd->right) {
		TreeNode *pS = nd->right;
		while (pS->left) pS = pS->left;
		return pS;
	}
	TreeNode *y = nd->p;
	TreeNode *x = nd;
	while (y && y->left != x) {
		x = y;
		y = y->p;
	}
	return y;
}

TreeNode* predecessor(TreeNode* nd) {
	if (nd->left) {
		TreeNode *pP = nd->left;
		while (pP->right) pP = pP->right;
		return pP;
	}
	
	TreeNode *y = nd->p;
	TreeNode *x = nd;
	while (y && y->right != x) {
		x = y;
		y = y->p;
	}
	return y;
}

TreeNode* minimum(TreeNode* root) {
	while (root->left) {
		root = root->left;
	}
	return root;
}

void transplant(TreeNode* rp, TreeNode* u, TreeNode* v) {
	if (u->p == nullptr) {
		rp->left = v;		
	}
	else if (u->p->left == u) {
		u->p->left = v;
	}
	else if (u->p->right == u) {
		u->p->right = v;
	}
	
	if (v) v->p = u->p;
}
void BstDel(TreeNode*rp, TreeNode* root, int key) {
	if (!root) return;
	TreeNode *del = BstSearch_r(root, key);
	if (!del->left) {
		transplant(rp, del, del->right);
	}
	else if (!del->right) {
		transplant(rp, del, del->left);
	}
	else {
		TreeNode *ps = successor(del);
		
		if (del->right != ps) {
			transplant(rp, ps, ps->right);
			ps->right = del->right;
			ps->right->p = ps;
		}
		transplant(rp, del, ps);
		ps->left = del->left;
		ps->left->p = ps;
	}
	delete del;
	del = nullptr;
}

void TestBST(){
	cout << "---TestBST START---" << endl;
	vector<int> nums(InitNums(14));
	cout << "Data: " << endl;
	printNums(nums);
	sort(nums.begin() + 2, nums.end() - 2);
	printNums(nums);
	vector<int> nums2(nums.begin() + 2, nums.end() - 2);
	vector<int> insertNums(nums.begin(), nums.begin() + 2);
	insertNums.push_back(nums[13]);
	insertNums.push_back(nums[12]);
	cout << endl;
	//Create A Tree
	TreeNode dummy(-1);	
	buildBST(&dummy, nums2);
	
	//Travel
	cout << "TreeFirstOrderWalk: " << endl;
	TreeFirstOrderWalk(dummy.left);
	cout << endl;
	TreeFirstOrderWalk_ir(dummy.left);
	cout << endl << endl;
	cout << "TreeInOrderWalk: " << endl;
	TreeInOrderWalk(dummy.left);
	cout << endl;
	TreeInOrderWalk_ir(dummy.left);
	cout << endl << endl;
	cout << "TreePostOrderWalk: " << endl;
	TreePostOrderWalk(dummy.left);
	cout << endl;
	TreePostOrderWalk_ir(dummy.left);
	cout << endl << endl;
	
	for (int i = 0; i < insertNums.size(); ++i) {
		cout << "Insert key: " << insertNums[i] << endl;
		TreeInOrderWalk(dummy.left);
		cout << endl;
		BstInsert(dummy.left, insertNums[i]);
		TreeInOrderWalk(dummy.left);
		cout << endl << endl;
	}
	
	for (int i = 0; i < insertNums.size(); ++i) {
		cout << "Delete key: " << insertNums[i] << endl;
		TreeInOrderWalk(dummy.left);
		cout << endl;
		BstDel(&dummy, dummy.left, insertNums[i]);
		TreeInOrderWalk(dummy.left);
		cout << endl << endl;
	}
	
	cout << "---TestBST END---" << endl;
}