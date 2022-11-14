//----------------------------------------------------------------------------
//SORTING AN ARRAY -- insertiontion sort
//goes through each element in outer loop
//inserts into the place it should be by comparing in inner
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
void insertionSort(int * a, int n)
{
    int i, j, small;
    for(i=0; i<n; i++) 
    {   small=a[i];
        for(j=i-1; j>=0 && small<a[j]; j--) 
        {   
            a[j + 1] = a[j];//shifts each value to right by 1
            }
            a[j+1]=small;// sets the value at i to the pos it belongs
        }

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
    insertionSort(a,n);
    print(a,n);

    free(a);
    return 0;
}
