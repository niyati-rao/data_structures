//----------------------------------------------------------------------------
//implememnting linked lists-- singly linked ---
//REVERSING THE ARRAY (NOT RECURSIVELY??)
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

void reverse(struct node* *head)
{   //setting up basis
    struct node* prev = NULL;  
    struct node* current = *head;
 
    // reversing the arrows
    while (current != NULL)
    {
        struct node* nextNode = current->next;// saving the next node before arrow change
        current->next = prev;//pointing changed
 
        prev = current; //moving ahead
        current = nextNode;
    }
    *head = prev;//storing the last which is now first
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
    reverse(&head);// PASS ADDRESS CAUSE VALUE DOES NOT WORK NEED TO DIRECTLY ACCESS ADDRESS
    printf("REVERSED:\n");
    printf("DISPLAYING THE ENTIRE LIST VALUE\t NEXT ADDRESS\n");
    displayList();
    return 0;
}
