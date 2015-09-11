/*
 * myCircularLinkedList.c
 *
 *  Created on: 03-Sep-2015
 *      Author: nitesh_sinha
 */

#include <stdio.h>
#include "myHeader.h"

void pushCircular(struct node **headref, int data) {

	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	struct node *temp = *headref;

	newnode->data = data;
	newnode->next = *headref;

	if(*headref != NULL) {

		while(temp->next != *headref)
			temp=temp->next;

		temp->next = newnode;
	} else {
		//this will be first node and last node
		newnode->next = newnode;
	}

	*headref = newnode;
}

void printListCircular(struct node *head) {

	struct node * temp = head;

	if(head != NULL) {
		do {
			printf("%d->",temp->data);
			temp = temp->next;
		} while(temp->next != head);
		printf("\n");
	}

}
