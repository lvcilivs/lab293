#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* traverseTillEnd(Node*) ;
Node* traverseTillItem(Node*, int) ;

Node* create(int data, Node *next) {
	Node *newNode = (Node*) malloc(sizeof(Node)) ;
	//TODO: check if new node is null and malloc is failing...
	newNode -> data = data ;
	newNode -> next = next ;

	return newNode ;
}

Node* traverseTillEnd(Node *current) {
	if(current -> next == NULL) {
		return current ;
	}
	else {
		return traverseTillEnd(current -> next) ;
	}
}

Node* traverseTillItem(Node *current, int item) {
	if(current -> data == item) {
		return current ;
	}
	else {
		return traverseTillItem(current -> next, item) ;
	}
}


Node* prepend(int data, Node *head) {
	Node *newNode = create(data, head) ;
	head = newNode ;
	return head ;
}

Node* append(int data, Node *head) {
	//TODO: Corner cases
	Node *cursor = head ;
	if(cursor == NULL) {
		return NULL ;
	}
	
	cursor = traverseTillEnd(cursor) ;
	Node *newNode = create(data, NULL) ;
	cursor -> next = newNode ;

	return head ;
}

Node* insertAfter(int data, Node *head, int item) {
	//TODO: Corner cases
	Node *cursor = head ;
	cursor = traverseTillItem(cursor, item) ;

	Node *newNode = create(data, cursor -> next) ;
	cursor -> next = newNode ;

	return head ;
}

Node* deleteAfter(Node *head, int item) {
	Node *cursor = head ;
	cursor = traverseTillItem(cursor, item) ;

	Node *tmp = cursor -> next ;
	cursor -> next = tmp -> next ;
	free(tmp) ;
	return head ;
}

Node* reverseList(Node* head) {
	Node *previous ;
	Node *current = head ;
	Node *next ;

	while(current != NULL){
		next = current -> next ;
		current -> next = previous ;
		previous = current ;
		current = next ;
	}

	head = previous ;
	return head ;
}



