//Binary Search Tree from sorted array
//same method as recursive binary search
//CREATING A BALANCED BINARY SEARCH TREE
//++Insertion and Search Function
/* ================================================== */
//the condition is the left child is lesser than parent
//and in the right child is greater than the parent
/* ================================================== */
#include<stdio.h>
#include<stdlib.h>

struct nodeType{//the structure of a node in BST
    int val;
    struct nodeType *left;
    struct nodeType *right;
};
typedef struct nodeType * NodeAddress;

/* ========================================================================= */
int* createList(int n)//an array sent in ascending order 0...n-1
{
    int * t = malloc( n * sizeof(int) );
    if(t) {
        for(int i=0; i<n; i++) 
            {t[i] = 2*i;}
    }
    return t;
}
/* ========================================================================= */
void printArray(int *a, int n)//from debg's code 
{
    printf("Array = ");
    for(int i=0; i<n; i++) {
        printf( i?", %d":"%d", a[i]);
    }
    printf("\n");
}
/* ========================================================================= */
NodeAddress createNode(int value)//creating a node and returning its address
{
    NodeAddress node=(NodeAddress)malloc(sizeof(struct nodeType));
    node->val=value;
    node->right=NULL;
    node->left=NULL;
    return node;
}
/* ========================================================================= */
NodeAddress createBSTfromList(int list[],int l,int r )//using a method like binary search
{
    if(l>r)
    {return NULL;}
    int mid= (l+r)/2;
    NodeAddress parent = createNode(list[mid]);//creates a node
    parent->left=createBSTfromList(list,l,mid-1);//left range of vals 
    parent->right=createBSTfromList(list,mid+1,r);//right range of vals
    return parent;
}
/* ========================================================================= */
void inorder(NodeAddress root)//this should give original array left-root-right debg block
{
    if( root->left!=NULL )  
        {inorder(root->left);}
    if( root!=NULL )       
        {printf(" %d ",root->val);}
    if( root->right!=NULL ) 
        {inorder(root->right);}
}
/* ========================================================================= */
NodeAddress search(NodeAddress root, int val)//recursively searches until value is reached
{
    if(root==NULL) return NULL;

    if      ( val < root->val ) {return search(root->left , val);}
    else if ( val > root->val ) {return search(root->right, val);}
    else                        {return root;}
}
/* ========================================================================= */

NodeAddress insert(NodeAddress root, int val)//from debg's code
{
    if(root==NULL) 
        {return createNode(val);}

    if ( val < root->val ) 
    { 
        if(root->left!=NULL)
            {return insert(root->left, val);}
        else 
            root->left = createNode(val);
        return root->left;
    }
    else if ( val > root->val ) 
    { 
        if(root->right!=NULL) 
            {return insert(root->right, val);}
        else 
            root->right = createNode(val);
        return root->right;
    }
    
    return root;
}

void main()//driver code
{
    int n=12;//number of nodes
    int ser=9;//value to be searched
    int insertedVal=7;//val to be inserted
    NodeAddress root;//to point at the root
    NodeAddress location;//points at location value searched element is stored in
    NodeAddress filledAt;
    int *a=createList(n);
    printArray(a,n);
    root=createBSTfromList(a,0,n-1);
    printf("PRINTING THE NODES INORDER\n");
    inorder(root);
    location =search(root,ser);
    if(location!=NULL)
        {printf("\nthe value %d  is at address %p",ser,location);}
    else
        {printf("\n%d, not found",ser);}
    filledAt=insert(root,insertedVal);
    printf("\nthe value %d  is inserted at address %p",insertedVal,filledAt);
    printf("\nPRINTING THE NODES INORDER\n");
    inorder(root);
}
