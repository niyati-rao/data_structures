//----------------------------------------------------------------------------
//SORTING AN ARRAY -- selection sort
//select smallest element shift, and shifts to beginning 
//Changes made to DEBG'S CODE (very subtle)
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

int * createArray(int n) {
    int * array = malloc( n * sizeof(int) );
    if(array) {
        for(int i=0; i<n; i++)
         {
            array[i] = rand()%100;//randoml
        }
    }
    return array;
}

//==================================================== 
void selectionSort(int * a, int n)
{
    int temp, i, j, pos;
    for(i=0; i<n; i++) 
    {
        pos=i;
        for(j=i; j<n; j++) 
        {
            if( a[j] < a[pos]) {//finds smallest element
                pos    = j;
            }
        }
        temp=a[i];//swapsss
        a[i]=a[pos];
        a[pos]=temp;
    } // end of the done loop
}
//==================================================== 
void print(int *a, int length) {
    for(int i=0; i<length; i++) {
        printf( i?", %d":"%d", a[i]);//
    }
    printf("\n");
}

//=====================================================
int main(int argc, char **argv) {
    int * a;
    int n = 10;

    a = createArray(n);
    printf("The Array:\n");
    print(a,n);
    printf("The Selection Sorted Array:\n");
    selectionSort(a,n);
    print(a,n);

    free(a);
    return 0;
}
