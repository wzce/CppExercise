//#include<iostream>
/**
题目描述：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）
形成树的一条路径，最长路径的长度为树的深度。
*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {
	}
};
class Solution {
public:
	//递归的实现方式
	int TreeDepth(TreeNode* pRoot)
	{
		return childDepth(pRoot);
	}

	int childDepth(TreeNode* node){
		if (node == nullptr){
			return 0;
		}
		else{
			int leftDepth = childDepth(node->left);
			int rigthDepth = childDepth(node->right);
			return 1 + (leftDepth>rigthDepth?leftDepth:rigthDepth);
		}
	}
};