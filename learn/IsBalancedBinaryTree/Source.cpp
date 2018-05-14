/*
��Ŀ������
����һ�ö��������жϸö������Ƿ���ƽ�������
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
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == nullptr){
			return true;
		}
		else{
			if (!(pRoot->left != nullptr && pRoot->val > pRoot->left->val)){
				return false;
			}

			if (!(pRoot->right != nullptr && pRoot->val < pRoot->right->val)){
				return false;
			}

			return (abs(depth(pRoot->left), depth(pRoot->right)) <= 1
				&& IsBalanced_Solution(pRoot->left)
				&&  IsBalanced_Solution(pRoot->right));
		}
	}

	int depth(TreeNode* node){
		if (node == nullptr){
			return 0;
		}
		else{
			int leftDepth = depth(node->left);
			int rigthDepth = depth(node->right);
			return 1 + (leftDepth>rigthDepth ? leftDepth : rigthDepth);
		}
	}
	int abs(int a, int b){
		if (a>b){
			return a - b;
		}
		else{
			return b - a;
		}
	}
};