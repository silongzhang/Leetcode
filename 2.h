// #2 两数相加

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	ListNode *addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *dummyHead = new ListNode(0);
		ListNode *lastNode = dummyHead;
		int carry = 0;
		ListNode *pos1 = l1, *pos2 = l2;
		while (pos1 != NULL || pos2 != NULL) {
			int num1 = (pos1 != NULL) ? pos1->val : 0;
			int num2 = (pos2 != NULL) ? pos2->val : 0;
			int num = num1 + num2 + carry;
			lastNode->next = new ListNode(num % 10);
			lastNode = lastNode->next;
			carry = num / 10;
			if (pos1 != NULL)pos1 = pos1->next;
			if (pos2 != NULL)pos2 = pos2->next;
		}
		if (carry > 0)lastNode->next = new ListNode(carry);
		return dummyHead->next;
	}
};

