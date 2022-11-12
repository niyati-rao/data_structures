#include <stdio.h>
#include <stdlib.h>
//---------------------------------weird strings-------------------------------
//-----------------------------------------------------------------------------
int main()
{
//---------------------------------string literals-----------------------------
char* s= "Old McDonald Had a Farm\n";//is a string- literal allocated memory in read-only section.
printf(s);
printf("character at pos 1: %c\n", s[1]);
printf("character at pos 1: %c\n\n", *(s+1));

//---------------------------------string as character array-------------------

char s0[] = " Old McDonald Had a Farm"; //is a character array where memory will be allocated in stack.
printf(s0);
printf("\nNOW AFTER MODIFICATION \n");
//s[0] = ''C ; Not allowed. It is undefined behaviour.
s0[0] = 'C' ; //Valid.
printf("%s",s0);

//---------------------------------FROM LECTURE NOTES---------------------------

char s1[ ] = { 'H', 'E', 'L', 'L', 'O', '\0' };
char s2[ ] = "hello"; // Array of size six with the last element being the null character
char s3[ 20 ] = "hello"; // Fifteen null bytes
char s4[ 5 ] = "hello"; // Five chars, sacrifices the null byte
//char s5[ 3 ] = "hello"; // IllegaL

//--------------------------------MORE ON POINTERS-------------------------------
printf("\n----------MORE ON POINTER---------\n");
const int var =10;// const part is disregarded
printf("address of var = %p\n", &var);
int *ptr = &var;
*ptr=12;
printf("AFTER SETTING PTR\n");
printf("var = %d\n", var);
printf("address of var = %p\n", &var);
printf("*ptr = %d\n", *ptr);
return 0;

}
