//#include<iostream>
/**
��Ŀ������
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩
�γ�����һ��·�����·���ĳ���Ϊ������ȡ�
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
	//�ݹ��ʵ�ַ�ʽ
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