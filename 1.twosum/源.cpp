#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int val, status = 0;
	struct ListNode* l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* T = (struct ListNode*)malloc(sizeof(struct ListNode));
	l3->next = NULL;
	T = l3;
	while (l1&&l2) {
		if (status == 0) {
			val = l1->val + l2->val;
			if (val >= 10) {
				val = val % 10;
				status = 1;
			}
		}
		else if (status == 1) {
			val = l1->val + l2->val + 1;
			status = 0;
			if (val >= 10) {
				val = val % 10;
				status = 1;
			}
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = val;
		node->next = NULL;
		T->next = node;
		T = T->next;
		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1) {
		if (status == 0) {
			T->next = l1;
			break;
		}
		else if (status == 1) {
			val = l1->val + 1;
			if (val == 10) 
				val = 0;
			else
				status = 0;
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = val;
		node->next = NULL;
		T->next = node;
		T = T->next;
		l1 = l1->next;
	}
	while (l2) {
		if (status == 0) {
			T->next = l2;
			break;
		}
		else if (status == 1) {
			val = l2->val + 1;
			if (val == 10)
				val = 0;
			else
				status = 0;
		}
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = val;
		node->next = NULL;
		T->next = node;
		T = T->next;
		l2 = l2->next;
	}
	if (status == 1) {
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = 1;
		node->next = NULL;
		T->next = node;
	}

	return l3->next;
}



int main(void) {
	
}