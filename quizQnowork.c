/*========================================================================
PROGRAM-
to create reverse BST, left child is greater than parent
and right child is smaller than parent.
BST can degenerate into a linked list
===========================================================================
*/
#include<stdio.h>
#include<stdlib.h>

struct nodeBST{//the structure of a node in BST
    int val;
    struct nodeBST *left;
    struct nodeBST *right;
};
typedef struct nodeBST * NodeAddress;

/* ========================================================================= */
NodeAddress arrayToReverseBST ( int *a , int n )//using the same code as insert
{
	NodeAddress root=NULL;
	for( int i=0 ; i<n; i++ )
	{
		insert(root,a[i]);
	}
	return root;
}
/* ========================================================================= */
void insert(NodeAddress root, int val)//from lecture code
{
	if(root==NULL) // if nothing has been added to list
        { root=createNode(val);}

    else if ( val > root->val ) 
    { 
        if(root->left!=NULL)
            {insert(root->left, val);}
        else 

            root->left=createNode(val);
    }
    else if ( val < root->val ) 
    { 
        if(root->right!=NULL) 
            {return insert(root->right, val);}
        else 
            root->right=createNode(val);
    }
    return;
}
/* ========================================================================= */
NodeAddress createNode(int value)//creating a node and returning its address
{
    NodeAddress node=(NodeAddress)malloc(sizeof(struct nodeBST));
    node->val=value;
    node->right=NULL;
    node->left=NULL;
    return node;
}
/* ========================================================================= */
void prefixPrint(NodeAddress root)//root-left-right// debg block from lecture
{
	if( root!=NULL )       
        {printf(" %d ",root->val);}
    if( root->left!=NULL )//function call stops at leaf nodes 
        {prefixPrint(root->left);}
    if( root!=NULL )       
        {printf(" %d ",root->val);}
    if( root->right!=NULL ) 
        {prefixPrint(root->right);}
}
/* ========================================================================= */
void main()
{
	int arr[]={12,4,9,63,7,18,27,67,8,2,72,1};
	int n=12;//number of nodes
	NodeAddress root;
	root=arrayToReverseBST(arr,n);
	prefixPrint(root);

}
