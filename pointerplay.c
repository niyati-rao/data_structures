//----------------------------------------------------------------------------
//pointer --- can point to a value of particular type
//memory adress --- a location oin memory &(variable)= its adress in memory
//      -use pointers because- saves space & time, efficient and dynamic
//      -& referencing operator while * dereferencing operator
//-----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
//----------------------------------POINTER PLAY-------------------------------
struct ptr{
    char *point;// creating alternate structures
};

int main()
{
//------------------------ * MEANS VALUE & MEANS ADDRESS ----------------------
    char ch='c';
    printf("constant is %c \n", ch );
    printf("address is  %p\n", &ch);// remember %p is to be used
//------------------------ USING NEWLY CREATED STRUCTURE  ----------------------
    struct ptr pointer;
    pointer.point = &ch;
    printf("using pointer is %c \n", *pointer.point);
//-----------------------IF TYPE IS * MEANS ADDRESS ---------------------------
    char *c= &ch;
    printf("constant is %c \n", *c );
    printf("address is  %p\n", c);// remember %p is to be used

}
