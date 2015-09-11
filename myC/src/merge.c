#include <stdio.h>
#include "myHeader.h"

/*{
	1.

} */

static
void FrontBackSplit(struct node *source, struct node **frontref, struct node **backref) {

	struct node *fast = source->next;
	struct node *slow = source;

	if(source == NULL || source->next == NULL) {
		//for case  < 2
		*frontref = source;
		*backref = NULL;
	} else {
		while (fast != NULL) {
			fast = fast->next;
			//move fast by two places
			if(fast != NULL) {
				slow = slow->next;
				fast = fast->next;
			}
		}
		//now slow will be at next of midpoint
		*frontref = source;
		*backref = slow->next;
		slow->next = NULL;
	}
}

static
struct node * SortedMerge(struct node *a, struct node *b) {

	struct node *result = NULL;

	if(a == NULL) {
		return b;
	} else if (b ==  NULL) {
		return a;
	}

	if(a->data <= b->data) {
		result = a;
		result->next = SortedMerge(a->next,b);
	} else {
		result = b;
		result->next = SortedMerge(a,b->next);
	}

	return result;
}

void MergeSort(struct node **headref) {

	struct node *head = *headref;
	struct node *a = NULL;
	struct node *b = NULL;

	if(head == NULL || head->next == NULL) {
		//printf("0 or 1 node only.");
		return;
	}

	FrontBackSplit(head,&a,&b);

	MergeSort(&a);
	MergeSort(&b);

	//call the merge subroutine and update the headref

	*headref = SortedMerge(a,b);

}
