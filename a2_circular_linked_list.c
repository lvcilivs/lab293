#include <stdio.h>
#include "circlist.h"

typedef void (*fpCallback) (Node *data) ;

void menu() {
	printf("### Linked List ### \n\n");
    printf("0.menu\n");
    printf("1.prepend an element\n");
    printf("2.append an element\n");
    printf("3.print the list\n");
    printf("4.print in reverse\n");
    printf("5.insert after an element\n");
    printf("6.delete after an element\n");
    printf("-1.quit\n");
}

void display(Node *n) {
	if(n != NULL)
		printf("%d ", n -> data) ;
}

void circTraverse(Node *head, fpCallback cb) {
	Node *cursor = head ;

	while(cursor -> next != head) {
		cb(cursor) ;
		cursor = cursor -> next ;
	}
	cb(cursor) ;
}

int main() {
	int choice = 0 ;
	int data, item ;

	Node *head = NULL ;
	Node *tmp = NULL ;

	fpCallback disp = display ;

	menu() ;

	while(1){
		printf("\nEnter a command: ") ;
        scanf("%d", &choice) ;

        if(choice == -1) {
            break ;
        }

        switch(choice) {
            case 0:
                menu() ;
                break ;

            case 1: 
            	printf("Enter a number to prepend: ") ;
                scanf("%d", &data) ;
                head = circPrepend(data, head) ;
                circTraverse(head, disp) ;
                break ;

            case 2: 
            	printf("Enter a number to append: ") ;
                scanf("%d", &data) ;
                head = circAppend(data, head) ;
                circTraverse(head, disp) ;
                break ;

            case 3:
            	circTraverse(head, disp) ;
            	break ;

            case 5:
                printf("Enter the value you want to insert after: ") ;
                scanf("%d", &item) ;
                printf("Enter a number: ");
                scanf("%d", &data) ;

                head = circInsertAfter(data, head, item) ;
                circTraverse(head, disp) ;
                break ;

               case 6: 
               	printf("Enter the value you want to delete after: ") ;
                scanf("%d", &item) ;

                head = circDeleteAfter(head, item) ;
                circTraverse(head, disp) ;
                break ;
		}
	}
}


