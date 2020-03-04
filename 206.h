// #206 ·´×ªÁ´±í

#include"linklist.h"
#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
	ListNode * reverseList(ListNode *head) {
		ListNode *prev = NULL;
		ListNode *curr = head;
		while (curr != NULL) {
			ListNode *temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}
		return prev;
	}
	ListNode * reverseList2(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		auto newHead = reverseList2(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}
};

