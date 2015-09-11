/*
 * myLinkedList.c
 *
 *  Created on: 12-Aug-2015
 *      Author: nitesh_sinha
 */

#include <stdio.h>
#include <stdlib.h>
#include "myHeader.h"

void printList(struct node *n) {

	while(n != NULL) {
		printf("%d->",n->data);
		n = n->next;
	}
	printf("\n");
}

void insertAfter(struct node *prev, int newdata) {

	if(prev->next == NULL) {
		printf("Given node cannot be null");
		return;
	}

	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next = prev->next;
	prev->next=newnode;
}

void append(struct node **headref, int newdata) {

	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = newdata;
	newnode->next = NULL;

	if(*headref == NULL) {
		*headref = newnode;
		return;
	}

	struct node *last = (*headref);
	while (last->next != NULL) {
		last = last->next;
	}

	last->next = newnode;
	return;
}

void deleteNode(struct node **headref, int key) {

	struct 	node *temp = *headref, *prev = NULL;

	if(temp != NULL && temp->data == key) {
		//if head node is the required node
		(*headref) = temp->next;
		free(temp);
	}

	while(temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL) {
		printf("Data not found.");
		return;
	}

	prev->next = temp->next;

	free(temp);

}

void deleteLinkedList(struct node **headref) {

	struct node *current = *headref, *next;

	while(current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}

	*headref = NULL;

}

void push(struct node **headref, int newdata) {

	struct node *newnode = (struct node*)malloc(sizeof(struct node));

	newnode->data = newdata;
	newnode->next = *headref;
	(*headref) = newnode;
}

void reverse(struct node **headref) {

	struct node *prev = NULL;
	struct node *current = *headref;
	struct node *next;

	while(current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*headref = prev;
}

int detectLoop(struct node *list) {

	struct node *slow = list, *fast = list;
	while(slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			printf("Loop Found!");
			return 1;
		}
	}
	return 0;
}

int length(struct node *head) {
	int len = 0;
	while(head != NULL) {
		len++;
		head = head->next;
	}
	return len;
}

struct node * unionList(struct node *a, struct node *b) {

	//assuming both a and b are sorted

	struct node *u = NULL;

	int i = 0, m = length(a);
	int j = 0, n = length(b);

	printf("A: len : %d\n", m);
	printf("B: len : %d\n", n);

	printList(a);
	printList(b);

	while(i<m && j<n) {
		if(a->data < b->data) {
			push(&u,a->data);
			a=a->next;
			i++;
		} else if (a->data > b->data) {
			push(&u,b->data);
			b=b->next;
			j++;
		} else {
			push(&u,b->data);
			a=a->next;
			b=b->next;
			i++,j++;
		}
	}

	while(i<m) {
		push(&u,a->data);
		a=a->next;
		i++;
	}

	while(j<n) {
		push(&u,b->data);
		b=b->next;
		j++;
	}

	return u;
}

void rotateList(struct node **headref, int k) {

	struct node *current = *headref;

	if(k == 0)
		return;

	int count = 1;
	while(count < k && current->next != NULL){
		current = current->next;
		count++;
	}

	struct node *kth = current;

	while(current->next != NULL) {
		current = current->next;
	}

	current->next = *headref;

	*headref = kth->next;
	kth->next = NULL;

}
