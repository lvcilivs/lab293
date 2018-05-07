#include <stdio.h>
#include <stdlib.h>
#include "list.h"

Node* circCreate(int data, Node *next) {
	return NULL ;
}

//TODO: Fix bug which prevents addition to an empty list
Node* circPrepend(int data, Node *head) {
	Node *cursor = head ;
	Node *newNode = create(data, head) ;

	if(head == NULL) {
		head = newNode ;
		newNode -> next = head ;
	}
	else {
		while(cursor -> next != head) {
			cursor = cursor -> next ;
		}
		newNode -> next = head ;
		head = newNode ;
		cursor -> next = head ;
	}

	return head ;
}

//TODO: Take care of the empty list corner case
Node* circAppend(int data, Node *head) {
	Node *cursor = head ;
	while(cursor -> next != head) {
		cursor = cursor -> next ;
	}

	Node *newNode = create(data, head) ;
	cursor -> next = newNode ;

	return head ;
}

//TODO: Take care of the not found corner case
Node* circInsertAfter(int data, Node *head, int item) {
	head = insertAfter(data, head, item) ;
	return head ;
}

//TODO: Take care of the deletion at end corner case
Node* circDeleteAfter(Node *head, int item) {
	head = deleteAfter(head, item) ;
	return head ;
}