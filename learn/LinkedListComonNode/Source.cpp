/*
题目描述：
	输入两个链表，找出它们的第一个公共结点。
*/
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(nullptr) {
	}
};
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* node1, ListNode* node2) {
		if (node1 ==nullptr || node1==nullptr){
			return nullptr;
		}
		node1->next = node2;
		ListNode * fast = node1;
		ListNode *slow = node1;
	
		do{
			fast = fast->next->next;
			slow = slow->next;
		} while (fast!=slow);

		return fast;
	}
};