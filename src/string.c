/*
 ============================================================================
 Name        : string.c
 Author      : sudheer
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//0(n) comppextiy. here adding node to the end
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct node{
	int data;
	struct node *next_node;
}__attribute__((packed)) node_s; //tells the compiler not to add padding between members of a struct.

node_s *__head = NULL;
node_s *__tail = NULL;

int init(int data){


	if(__head){
		printf("queue allready intialezed \n");
		return -1;
	}
	__head=malloc(sizeof(node_s));

	if(!__head){
		printf("memory allocation failed \n");
		return -2;
	}

	__head->next_node=NULL;
	__head->data = data;

	__tail=__head;

	//printf("%d \n", __head->data);
	return 0;
}

int enque(int data){ //add

	node_s *cursor;

	/* node */
	node_s *n= malloc(sizeof(node_s));
    if(!n){
        printf("memory allocation failed \n");
        return -1;
    }
	/* node end */

    // Initialize the new node with data and NULL pointer
	n->data = data;
	n->next_node = NULL;
	//printf("%d \n", n->data);


	/*tail start*/
	__tail->next_node=n;
	__tail=n;
	/* tail end*/



	return 0;

}
int deque() { 	// remove from front
	if (!__head)
	{
		printf("Queue is empty, cannot dequeue\n");
		return -1;
	}

	node_s *temp = __head;

	int value = temp->data;
	__head = __head->next_node; // If queue becomes empty, reset tail
	if (__head == NULL) {
		__tail = NULL;
	}
	free(temp);
	return value;

}
int traverse(){
	node_s *cursor =malloc(sizeof(node_s));

	for (cursor = __head; cursor != NULL; cursor = cursor->next_node) {
	    // Loop body (e.g., process cursor->data)
		printf("%d-->", cursor->data);
	}

	printf("{}\n");// {} represt null
}

int main(void) {

	/*this i ssimple linked list and time 0(1) taking less time
	 *  easch node it add in the begining
	 * */
	init(101);
	enque(102);
	enque(103);
	traverse();

	printf("Dequeued: %d\n", deque());
	traverse();
	printf("Dequeued: %d\n", deque());
	traverse();
	printf("Dequeued: %d\n", deque());
	traverse(); // Try dequeuing from empty queue deque();
	return EXIT_SUCCESS;
}









