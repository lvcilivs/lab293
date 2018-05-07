#include <stdio.h>
#include "list.h"

//TODO: Put traverse in the header file
void traverse(Node*) ;

int main() {
	int data ;
	int i = 0 ;
	Node *head = NULL ;

	while(1){
		printf("Enter a positive number, press -1 to exit insertion: ") ;
		scanf("%d ", &data) ;

		if(data == -1)
			break ;

		head = append(data, head) ;
		traverse(head) ;
	}

	printf("\n Reversing list...") ;
	reverseList(head) ;
	printf("\n Printing reverse list...") ;
	traverse(head) ;
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
