#include <stdio.h>
#include "list.h"

//TODO: Put traverse in the header file
void traverse(Node*) ;
Node* reverselist(Node*) ;

int main() {
	int data ;
	int i = 0 ;
	Node *head = NULL ;

	while(1){
		printf("\nEnter a positive number, press -1 to exit insertion: ") ;
		scanf("%d", &data) ;

		if(data == -1)
			break ;

		head = prepend(data, head) ;
		traverse(head) ;
	}

	printf("\n Reversing list...") ;
	head = reverselist(head) ;
	printf("\n Printing reverse list...") ;
	traverse(head) ;
	printf("\n") ;
	return 0 ;
}

//TODO: Make this immutable
void traverse(Node *head) {
	Node *cursor = head ;

	while(cursor != NULL) {
		printf("%d ", cursor -> data) ;
		cursor = cursor -> next ;
	}
}

Node* reverselist(Node *head) {
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
