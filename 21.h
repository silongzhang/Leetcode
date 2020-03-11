// #21 合并两个有序链表

#include"linklist.h"

class Solution {
public:
	ListNode *mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *preHead = new ListNode(-1);
		ListNode *pt = preHead;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				pt->next = l1;
				l1 = l1->next;
			}
			else {
				pt->next = l2;
				l2 = l2->next;
			}
			pt = pt->next;
		}
		pt->next = l1 == NULL ? l2 : l1;
		pt = preHead->next;
		delete preHead;
		return pt;
	}
};

