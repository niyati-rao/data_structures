//----------------------------------------------------------------------------
//implememnting linked lists-- singly linked ---
// from - https://webrewrite.com/program-reverse-linked-list-using-recursion/
//----------------------------------------------------------------------------
//REVERSING THE ARRAY RECURSIVELY
//----------------------------------------------------------------------------
//basically thinking first and the rest where array is divided into two parts
//recursively call until end reached then do the pointer changing  
//which is stacked up
//----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

struct node *head, *tail = NULL;
// creating a structure for each node
struct node{
    int val;
    struct node* next;
};

//given the number of nodes create a linked list
void createList(int num)
{
    for(int i=1; i<=num; i++)
    {
        struct node *temp=(struct node*) malloc(sizeof(struct node));
        temp->val=i;// val at each node is same as value of i
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        } 
        else
        {
            tail->next=temp;
            tail=temp;
        }      
    }
}

void reverse(struct node* ptr)
{   //setting up base case 
    if(ptr->next==NULL)
        {
            head=ptr;//reach end make it head
            return;
        }
    reverse(ptr->next);// vaguely understand need to dry run more
    struct node* r = ptr->next;
    r->next=ptr;
    ptr->next=NULL;
}

void displayList()//displaying the list 
{
    struct node *current =head;
    while(current!=NULL)// while memory not allocated
    {
        printf("%d\t",current->val);
        printf("%p\n",current->next);

        current=current->next;
    }
}


int main(){
    int n=16; //total number of values of a linked list
    createList(n);
    printf("ORIGINALLY:\n");
    printf("DISPLAYING THE ENTIRE LIST VALUE\t NEXT ADDRESS\n");
    displayList();
    printf("-----------------------------------------------\n");
    reverse(head);// PASS ADDRESS CAUSE VALUE DOES NOT WORK NEED TO DIRECTLY ACCESS ADDRESS
    printf("RECURSIVELY REVERSED:\n");
    printf("DISPLAYING THE ENTIRE LIST VALUE\t NEXT ADDRESS\n");
    displayList();
    return 0;
}
