#pragma once

#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


ListNode *buildLinkList(const vector<int> &data) {
	if (data.empty()) { return NULL; }

	auto pos = data.begin();
	ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	head->val = *pos;
	head->next = NULL;
	ListNode *lastNode = head;
	for (++pos; pos != data.end(); ++pos) {
		ListNode *pt = (ListNode *)malloc(sizeof(ListNode));
		pt->val = *pos;
		pt->next = NULL;
		lastNode->next = pt;
		lastNode = pt;
	}
	return head;
}


void printLinkList(const ListNode *const head) {
	for (auto pt = head; pt != NULL; pt = pt->next) {
		cout << pt->val << '\t';
	}
	cout << endl;
}

