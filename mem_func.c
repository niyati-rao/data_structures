//mostly from geeksforgeeks
//-----------------------------------------------------------------------------
//pointer --- can point to a value or an address
//malloc  --- memory allocation (size)
//realloc --- dynamically reallocates (pointer, new_size)
//calloc  --- contiguous memory allocation (number, size_of_one)
//free    --- free allocated memory space (pointer)
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//-----------------------------------MALLOC------------------------------------
void use_malloc(int n)
{
    char* pos= (char*) malloc(n*sizeof(char)); //pos is a pointer to the address
    if(n==0){
        printf("no values to be allocated");
        exit(0);}
    else
        {printf("\nmalloc space allocated\n");
            for(int i=0; i<n; i++){
                    pos[i]=(char)(i+65);// this means there is upperlimit sw
                }
            for(int i=0;i<n;i++){
                    printf("%c,", pos[i]);
                }
        }
    free(pos);   
}
//--------------------------------M-REALLOC------------------------------------
void m_realloc(int n)
{
    char* pos= (char*) malloc(n*sizeof(char)); //pos is a pointer to the address
    if(n==0){
        printf("no values to be allocated");
        exit(0);}
    else
        {printf("\nfirstly, malloc space allocated\n");
            for(int i=0; i<n; i++){
                    pos[i]=(char)(i+65);// this means there is upperlimit sw
                }
            for(int i=0;i<n;i++){
                    printf("%c,", pos[i]);
                }
        }
    n=n+2;
    pos=realloc(pos, (n)*sizeof(char));
    {printf("\n space reallocated allocated\n");
            for(int i=0; i<n; i++){
                    pos[i]=(char)(i+65);// this means there is upperlimit sw
                }
            for(int i=0;i<n;i++){
                    printf("%c,", pos[i]);
                }
        }

    free(pos);   
}
//------------------------------------CALLOC------------------------------------
void use_calloc(int n)
{   

    char* pos= (char*) calloc(n,sizeof(char)); //pos is a pointer to the address
    if(n==0){
        printf("space not allocated");
        exit(0);}
    else
        {printf("\ncalloc space allocated\n");
            for(int i=0; i<n; i++){
                    pos[i]=(char)(i+65);// this means there is upperlimit sw
                }
            for(int i=0;i<n;i++){
                    printf("%c,", pos[i]);
                }
        }
    free(pos);
}
//--------------------------------------------------------------------------------
int main()
{
    int size=10; // number of type- sized elements
    use_malloc(size);
    use_calloc(size+2);
    m_realloc(size);

}
