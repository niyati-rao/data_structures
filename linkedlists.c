#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}; 
int main()
{
struct node *prev,*head,*list;
int n;
    printf ("Enter number of elements:");
    scanf("%d",&n);// & means that its an address
    head=NULL; //head is null means no linked list exists
    printf("enter values:");
    for(int i=0;i<n;i++)
    {
        list=malloc(sizeof(struct node));// alloting space one node at a time
        scanf("%d",&list->value);
        list->next=NULL;
        if(head==NULL){
            head=list;//marking the head
        }
        else{
            prev->next=list;//
        }
        prev=list;// marking current node
    }
    list=head;
    while (list!=NULL)
    {
        printf("%d\n",list->value);
        list=list->next;
    }

    return 0;
}




