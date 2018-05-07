#include <stdio.h>
#include "list.h"

/**
TODO: 
1. Add appended deletion
2. Add prepended deletion
3. Implement search here
**/
//typedef struct Node node ;
typedef void (*fpCallback) (Node *data) ;

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

void display(Node *n) {
    if(n != NULL){
        printf("%d ", n -> data) ;
    }
}

void traverse(Node *head, fpCallback cb) {
    Node *cursor = head ;
    
    while(cursor != NULL) {
        cb(cursor) ;
        cursor = cursor -> next ;
    }
}

int main() {
    int choice = 0 ;
    int data, item ;

    Node *head = NULL ;
    Node *tmp = NULL ;

    fpCallback disp = display ;

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
                head = prepend(data, head) ;
                traverse(head, disp) ;
                break ;

            case 2: 
                printf("Enter a number to append: ") ;
                scanf("%d", &data) ;
                head = append(data, head) ;
                traverse(head, disp) ; //passing a functional pointer to prevent theoritical mutability
                break ;

            case 3:
                traverse(head, disp) ;
                break ; 

            case 4: 
                head = reverseList(head) ;
                traverse(head, disp) ;
                head = reverseList(head) ;
                break ;

            case 5: 
                printf("Enter the value you want to insert after: ") ;
                scanf("%d", &item) ;
                printf("Enter a number: ");
                scanf("%d", &data) ;

                head = insertAfter(data, head, item) ;
                traverse(head, disp) ;
                break ;

            case 6: 
                printf("Enter the value you want to delete after: ") ;
                scanf("%d", &item) ;

                head = deleteAfter(head, item) ;
                traverse(head, disp) ;
                break ;
        }
    }

    return 0 ;
}