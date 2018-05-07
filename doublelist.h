#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode {
	int data ;
	struct Dnode *next ;
	struct Dnode *prev ;
} Dnode ;

//TODO: Take care if malloc fails
Dnode* dCreate(int data, Dnode *next, Dnode* prev) {
	Dnode *newNode = (Dnode*) malloc(sizeof(Dnode)) ;

	newNode -> data = data ;
	newNode -> next = next ;
	newNode -> prev = prev ;

	return newNode ;
}

Dnode* dPrepend(int data, Dnode *head) {
	Dnode *newNode ;
	if(head == NULL) 
		newNode = dCreate(data, NULL, NULL) ;
	else
		newNode = dCreate(data, head, NULL) ;
		
	head = newNode ;
		
	return head ;
}

//TODO: Corner case for entering in an empty list
Dnode* dAppend(int data, Dnode *head) {
	Dnode *cursor = head ;
	while(cursor -> next != NULL) {
		cursor = cursor -> next ;
	}
	
	Dnode *newNode = dCreate(data, NULL, cursor) ;
	
	return head ;
}