// #19 删除链表的倒数第N个节点

#include"linklist.h"

#include<iostream>

using namespace std;

class Solution {
public:
	ListNode *removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) return NULL;
		ListNode *tail = head;
		int i = 1;
		for (; i < n && tail->next != NULL; ++i, tail = tail->next) {}
		if (i < n) return NULL;
		ListNode *pos = head, *lastNode;
		if (tail->next == NULL) head = head->next;
		else {
			for (; tail->next != NULL; pos = pos->next, tail = tail->next) {
				lastNode = pos;
			}
			lastNode->next = lastNode->next->next;
		}
		delete pos;
		return head;
	}
};

