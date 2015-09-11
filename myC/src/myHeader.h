/*
 * myHeader.h
 *
 *  Created on: 12-Aug-2015
 *      Author: nitesh_sinha
 */

#ifndef MYHEADER_H_
#define MYHEADER_H_

struct node {
	int data;
	struct node *next;
};

struct dnode {
	int data;
	struct dnode *prev;
	struct dnode *next;
};

void push(struct node **,int );
void insertAfter(struct node *,int );
void append(struct node **,int );
void printList(struct node *);
void deleteNode(struct node **, int key);
void reverse(struct node **);
int detectLoop(struct node *);
int length(struct node *);
void deleteLinkedList(struct node **);
void MergeSort(struct node **);
struct node * unionList(struct node *, struct node *);
struct node * intersectionList(struct node *, struct node *);
void rotateList(struct node **, int );

void pushCircular(struct node **, int );
void printListCircular(struct node *);

void pushDoubleLL(struct dnode **, int );
void printListDLL(struct dnode *);

#endif /* MYHEADER_H_ */

