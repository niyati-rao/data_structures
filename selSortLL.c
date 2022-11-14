#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int val;
    struct node * next; 
};
typedef struct node * NodeAddress;

/* ================================================== */

NodeAddress selectionSortLinkedList(NodeAddress head) {
    NodeAddress i,j, small;
    int temp;
    for(i=head; i->next!=NULL; i=i->next) {
        small=i;
        for(j=i->next; j!=NULL ; j=j->next) {

            if( j->val < small->val ) {
                small = j; // pointer points at the smallest element
            }}
            temp=i->val;//swapping values
            i->val=small->val;
            small->val=temp;
        } //end loop
return head;
    }


/* ================================================== */
NodeAddress linkedList( int n) {
    int i;
    NodeAddress head = NULL;
    NodeAddress temp = NULL;

    // special case for head
    if(n>0) {
        head = malloc( sizeof(struct node) );
        head->val  = rand()%1000;
        head->next = NULL;
        temp = head;
    }


    for(i=1; i<n; i++) {
        temp->next = malloc( sizeof(struct node) );
        temp = temp->next;
        temp->val = rand()%1000;
        temp->next = NULL;
    }

    return head;
}

void freeLinkedList(NodeAddress head) {
    NodeAddress prev;
    while(head) {
        prev = head;
        head = head->next;
        free(prev);
    }
}

/* ================================================== */

void printLinkedList(NodeAddress head) {
    NodeAddress c;
    printf("Linked List = ");
    for(c=head; c!=NULL; c=c->next) {
        printf( c==head?"%d":", %d", c->val);
    }
    printf(".\n");
}

/* ================================================== */
int main(int argc, char **argv) {
    int n = 10;
    NodeAddress list;

    srand(time(NULL));
    list = linkedList(n);

    printLinkedList(list);
    selectionSortLinkedList(list);
    printLinkedList(list);
    freeLinkedList(list);

    return 0;
}
