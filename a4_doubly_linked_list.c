#include <stdio.h>
#include "doublelist.h"

void menu()
{
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


void dTraverse(Dnode *head){
	Dnode *cursor = head ;
	while(cursor -> next != NULL) {
		printf("%d ", cursor -> data) ;
		cursor = cursor -> next ;
	}
}

int main() {
    int choice = 0 ;
    int data, item ;

    Dnode *head = NULL ;
    Dnode *tmp = NULL ;

    //fpCallback disp = display ;

    menu() ;

    while(1) {
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
                head = dPrepend(data, head) ;
                dTraverse(head) ;
                break ;

            case 2: 
                printf("Enter a number to append: ") ;
                scanf("%d", &data) ;
                head = dAppend(data, head) ;
                dTraverse(head) ; //passing a functional pointer to prevent theoritical mutability
                break ;
        }
    }
}
