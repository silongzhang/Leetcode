// #23 合并K个排序链表

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
	vector<ListNode*> mergeKListsCore(vector<ListNode*>& lists) {
		vector<ListNode*> ans;
		for (int i = 0; i < lists.size(); i += 2) {
			if (i + 1 < lists.size()) ans.push_back(mergeTwoLists(lists[i], lists[i + 1]));
			else ans.push_back(lists[i]);
		}
		return ans;
	}
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return NULL;
		vector<ListNode*> ans = mergeKListsCore(lists);
		for (; ans.size() > 1; ans = mergeKListsCore(ans)) {}
		return ans[0];
	}
};

