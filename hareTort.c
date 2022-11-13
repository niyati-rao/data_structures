//----------------------------------------------------------------------------
//implememnting linked lists-- singly linked ---
//++ HARE and TORTOISE method
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>

struct list *head, *tail = NULL;
// creating a structure for each node
struct list{
    int val;
    struct list* next;
};

//given the number of nodes create a linked list
void createList(int num)
{
    for(int i=1; i<=num; i++)
    {
        struct list *temp=(struct list*) malloc(sizeof(struct list));
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

void displayList()//displaying the list 
{
    struct list *current =head;
    while(current!=NULL)// while memory not allocated
    {
        printf("%d\t",current->val);
        printf("%p\n",current->next);

        current=current->next;
    }
}

void displayHalfList()
{   struct list *tortoise =head;
    struct list *hare =head;
    while(hare!=NULL )
    {   
        if(hare->next==NULL)// i know this way looks bad but 
        {break;}//couldn't find a better way to this :((
         else
        hare=hare->next->next;//hare moves ahead by 2
        printf("%d\t",tortoise->val);
        //printf("%p\n",tortoise->next);

        tortoise=tortoise->next;// tortoise moves by 1
    }
    
        
}
int main(){
    int n=16; //total number of values of a linked list
    createList(n);
    printf("DISPLAYING THE ENTIRE LIST VALUE\t NEXT ADDRESS\n");
    displayList();
    printf("DISPLAYING HALF LIST VALUE\n");
    displayHalfList();
    return 0;
}


