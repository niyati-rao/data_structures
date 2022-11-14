/* ================================================== */
//INSERTION SORTING A LINKED LIST
// for some reason feels wrong because of the order but
//not really sure
/* ================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int val;
    struct node * next; 
};
typedef struct node * NodeAddress;

/* ================================================== */
 
NodeAddress insertionSortLinkedList(NodeAddress head) {
    NodeAddress i,j,small,prev;
    int temp;
    for(i=head->next; i!=NULL; i=i->next) {
        for(j=head; j!=i; j=j->next)
        {   if(j->val>i->val)
            {
            temp=i->val;
            i->val=j->val;
            j->val=temp; 
            }        
            }
        }
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
    insertionSortLinkedList(list);
    printLinkedList(list);
    freeLinkedList(list);

    return 0;
}
