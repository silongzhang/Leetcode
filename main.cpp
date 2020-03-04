#include"linklist.h"
#include"2.h"


int main() {
	vector<int> vec1 = { 4,5,6,7 }, vec2 = { 7,3,8,9,4 };
	ListNode *l1 = buildLinkList(vec1), *l2 = buildLinkList(vec2);
	printLinkList(l1); printLinkList(l2);
	Solution sol;
	auto head = sol.addTwoNumbers(l1, l2);
	printLinkList(head);
	return 0;
}

