#include <stdio.h>
#include "myHeader.h"

int main() {
	//printf("%s\n","Nitesh");

	struct node *head = NULL;
//
//	append(&head,10);
//	append(&head,20);
//
//	push(&head,1);
//	push(&head,2);
//	push(&head,3);
//
//	insertAfter(head,45);
//	insertAfter(head,67);
//
//	printList(head);
//
//	deleteNode(&head,2);
//
//	printList(head);
//
//	reverse(&head);
//
//	//head->next->next->next->next->next = head;
//	//detectLoop(head);
//
//	printList(head);
//
//	printf("Length is: %d\n",length(head));
//
//	printf("Before MergeSort: \n");
//	printList(head);
//
//	MergeSort(&head);
//
//	printf("After MergeSort:\n ");
//	printList(head);


//struct node *one = NULL;
//struct node *two = NULL;
//struct node *three = NULL;

//push(&one,1);
//push(&one,3);
//push(&one,5);
//push(&one,6);
//push(&one,2);
//push(&one,7);
//push(&one,8);
//push(&two,2);
//push(&two,6);
//push(&two,8);

//three = unionList(one,two);

//printList(one);

//rotateList(&one,2);

//printList(one);

	pushCircular(&head,2);

	printListCircular(head);

	pushCircular(&head,6);
	pushCircular(&head,8);

	printListCircular(head);




	return 0;
}
