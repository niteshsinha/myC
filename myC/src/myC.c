/*
 ============================================================================
 Name        : myC.c
 Author      : Nitesh Sinha
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//int lsearch(int key,int array[],int size){
//	for(int i=0;i<size;i++){
//		if(array[i]==key)
//			return i;
//	}
//	return -1;
//}
// will work for all primitive types, but not strings, structs
//void* lsearch(void *key,void *base,int n,int elemSize){
//	for(int i=0; i<n; i++){
//		//void *elemAddr = base + i * elemSize;
//		void *elemAddr = (char*) base + i * elemSize;
//		if(memcmp(key,elemAddr,elemSize) == 0)
//			return elemAddr;
//	}
//	return NULL;
//}

//this is comparison function, called from below
int IntCmp(void *elem1, void *elem2){
	int *ip1 = elem1;
	int *ip2 = elem2;
	return *ip1 - *ip2;
}

int StrCmp(void *vp1, void *vp2){
	char *s1 = *(char **) vp1;
	char *s2 = *(char **) vp2;

	return strcmp(s1,s2);
}

//will work for structs as well
void* lsearch(void *key, void *base, int n,int elemSize, int (*cmpfn) (void *, void *)){
	for(int i=0; i<n; i++){
		void *elemAddr = (char *)base + i * elemSize;
		if(cmpfn(key,elemAddr) == 0)
			return elemAddr;
	}
	return NULL;
}



//generic swap function
void swap(void* vp1, void* vp2,int size){

	char buffer[size];
	memcpy(buffer,vp1,size);
	memcpy(vp1,vp2,size);
	memcpy(vp2,buffer,size);
}

void generateTwoRandomNums(int* rand1, int* rand2){

	*rand1 = rand() % 50 +1;
	*rand2 = rand() % 50 +1;

	printf("New rand1 in functions = %d\n\n",*rand1);

	printf("New rand2 in functons = %d\n\n",*rand2);
}

void editMessageSent(char* message, int size){
	char newMessage[] ="New Message";

	if(size > sizeof(newMessage)){
		for(int i=0; i<sizeof(newMessage);i++){
			message[i] = newMessage[i];
		}
	} else {
		printf("New Message is too big");
	}
}

//int main(void) {
void someFunction() {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	int rand1 =12, rand2=15;
	printf("rand1 = %p : rand2 = %p \n\n",&rand1,&rand2);

	printf ("rand1 = %d : rand2 = %d\n\n",&rand1,&rand2);

	printf("Size of int %d\n\n",sizeof(rand1));

	int *pRand1 = &rand1;

	printf("Pointer rand1: %p\n\n",pRand1);

	printf("Values %d\n\n",*pRand1);

	int primeNumbers[] = {2,3,4,5};

	printf("First Index: %d\n\n",primeNumbers[1]);

	printf("First Index: %d\n\n",*(primeNumbers+1));


	char * students[4] = {"Sally","Mark","Paul","Sue"};

	for(int i=0; i<4;i++){
		printf("%s : %d\n\n",students[i],&students[i]);
	}

	printf("Main before functions call");

	printf("rand1 = %d\n\n",rand1);
	printf("rand2 = %d\n\n",rand2);

	generateTwoRandomNums(&rand1,&rand2);

	printf("rand1 = %d\n\n",rand1);
	printf("rand2 = %d\n\n",rand2);

	printf("Main After function call");

	char randomMessage[] = "Edit my function";

	printf("Old Message: %s\n\n",randomMessage);

	editMessageSent(randomMessage,sizeof(randomMessage));

	printf("New Message: %s\n\n",randomMessage);

	printf("Generic Swap function below \n");

	int x=3,y=5;
	swap(&x,&y,sizeof(int));
	printf("x = %d and y = %d \n",x,y);

	float a = 1.234,b=5.667;
	swap(&a,&b,sizeof(float));
	printf("a = %f and b = %f \n",a,b);

	char* name = "Nitesh is here";
	char* surname = "Sinha";
	swap(&name,&surname,sizeof(char *));
	printf("Name = %s  and Surname = %s \n",name,surname);

	char* husband = strdup("Fred");
	char* wife = strdup("Wilmaxyz");

	swap(husband,wife,sizeof(char *));
	printf("Husband = %s and Wife = %s \n",husband,wife);


	int array[] = {4,2,3,7,11,6};
	int size = 6;
	int number = 8;

	int *found = lsearch(&number,array,6,sizeof(int),IntCmp);

	if(found == NULL)
		printf("Not Found\n");
	else
		printf("Found\n");

	char* notes[]={"Ab","F#","B","Gb","D"};

	char* favourite = "Gb";

	char **found1 = lsearch(&favourite,notes,5,sizeof(char *),StrCmp);

	printf("Return - %s ",*found1);

	if(found1 == NULL)
		printf("String Not Found\n");
	else
		printf("String Found\n");

	//return EXIT_SUCCESS;
}
